#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int value;
    int count;
    Node* next;
    Node() : value(0), count(0), next(nullptr) {}
    Node(int v, int c) : value(v), count(c), next(nullptr) {}
};

void print_list(Node* head) {
    while (head != NULL) {
        if (head->next == nullptr) {
            cout << head->value;
        } else {
            cout << head->value << "->";
        }
        head = head->next;
    }
    cout << endl;
}

void insert_front(Node** head, int newValue) {
    Node* newNode = new Node(newValue, 0);
    newNode->next = *head;
    *head = newNode;
}

void insert_given_poss(Node** head, int newValue, int position) {
    if (position == 0) {
        insert_front(head, newValue);
        return;
    }

    Node* newNode = new Node(newValue, 0);
    Node* targetNode = *head;
    int count = 1;
    while (count < position - 1 && targetNode != nullptr) {
        targetNode = targetNode->next;
        count += 1;
    }

    if (targetNode == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }

    newNode->next = targetNode->next;
    targetNode->next = newNode;
}

bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void prime_factorization(Node** head, int number) {
    int prime = 2;
    int position = 0;

    while (number > 1) {
        if (number % prime == 0) {
            number /= prime;
            insert_given_poss(head, prime, position);
            position++;
        } else {
            prime++;
            while (!is_prime(prime)) {
                prime++;
            }
        }
    }
}

Node* pack_primes(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty" << endl;
        return nullptr;
    }

    Node* thead = *head, *new_head = nullptr, *current = nullptr;

    while (thead) {
        bool found = false;
        for (Node* node = new_head; node; node = node->next) {
            if (node->value == thead->value) {
                node->count++;
                found = true;
                break;
            }
        }
        if (!found) {
            Node* new_node = new Node(thead->value, 1);
            if (!new_head)
                new_head = current = new_node;
            else
                current = current->next = new_node;
        }

        thead = thead->next;
    }

    // printing
    Node* temp = new_head;
    while (temp) {
        if (temp->next != NULL) {
            cout << "{ " << temp->value << "," << temp->count << " } ";
        } else {
            cout << "{ " << temp->value << "," << temp->count << " }";
        }
        temp = temp->next;
    }
    return new_head;
}

int main() {

    Node* head = nullptr;

    int number;
    cout << "Enter The Number: ";
    cin >> number;

    prime_factorization(&head, number);

    pack_primes(&head);

    return 0;
}
