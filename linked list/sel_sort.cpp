#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Node {
    public:
        long long int value;
        Node* next;
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

void print_list(Node** start) {
    Node * temp_start = *start;
    Node * head = temp_start->next;
    while(head != nullptr){
        if(head->next == nullptr){
            cout << head->value;
        }else{
        cout << head->value << "->";
        }
        head = head->next;
    }
    cout << endl;
}

void insert_front(Node** start, int value){
    Node* t_start = *start;
    Node* node = new Node();
    node->value = value;

    if(t_start->next == nullptr){
        t_start->next = node;
        node->next = nullptr;
    } else {
        Node* temp = t_start->next;
        t_start->next = node;
        node->next = temp;
    }
}

int find_max(Node** start) {
    Node* t_start = *start;
    Node* t_head = t_start->next;
    Node* c_node = t_head;
    int max = t_head->value;

    while (t_head != nullptr) {
        if (max <= t_head->value) {
            max = t_head->value;
            c_node = t_head;
        }
        t_head = t_head->next;
    }
    c_node->value = max - 100000000000000000;
    return max;
}

void sorting(Node** start) {
    Node* t_start = *start;
    Node* new_start = new Node();
    Node* head = t_start->next;

    while (head != nullptr) {
        int max = find_max(&t_start);
        insert_front(&new_start, max);
        head = head->next;
    }
    print_list(&new_start);
}

void memory_clean(Node** start) {
    Node* current = *start;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    *start = nullptr; 
    delete next;
    delete current;
    cout << "Memory Cleaned Successfully" << endl;
}


int main() {
    Node* start = new Node();

    cout << "When you are finished typing, type end" << endl;

    take_values(&start);

    cout << "Unsorted list" << endl;
    print_list(&start);

    cout << endl;

    cout << "Sorted list" << endl;
    sorting(&start);

    cout << endl;

    memory_clean(&start);

    return 0;
}
