#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node *next;
};

Node* take_values(Node** start) {
    Node* temp_start = *start;
    string value;

    do {
        cout << "Enter the value : ";
        cin >> value;
        if (value != "end") {
            if (temp_start->next == nullptr) {
                Node* head = new Node();
                head->value = stoi(value);
                head->next = nullptr;
                temp_start->next = head;
                temp_start = head;
            } else {
                Node* node = new Node();
                node->value = stoi(value);
                node->next = temp_start->next;
                temp_start->next = node;
            }
        }
    } while (value != "end");
    return temp_start;
}

void insert_front(Node** head, int newValue){
    Node* newNode = new Node();
    newNode->value = newValue;

    newNode->next = *head;

    *head = newNode;
}

void insert_given_pos(Node** head, int newValue, int position) {
    Node* newNode = new Node();
    newNode->value = newValue;

    if (position == 0) {
        insert_front(head, newValue); // Call to the insert_front function
        return;
    }

    Node* targetNode = *head;
    int count = 1;

    while (count < position && targetNode != nullptr) {
        targetNode = targetNode->next;
        count += 1;
    }

    if (targetNode == nullptr) {
        std::cout << "Position out of bounds" << std::endl;
        return;
    }

    newNode->next = targetNode->next;
    targetNode->next = newNode;
}

// Example usage:
int main() {
    Node* head = new Node();
    take_values(&head);

    insert_given_pos(&head, 31, 4);

    Node* current = head->next;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    return 0;
}
