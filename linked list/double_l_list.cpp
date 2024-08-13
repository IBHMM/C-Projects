#include <iostream>

class Node {
    public:
        int data;
        struct Node* prev;
        struct Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** headRef, int data) {
    Node* new_node = createNode(data);
    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void prepend(Node** headRef, int data) {
    Node* new_node = createNode(data);
    new_node->next = *headRef;
    if (*headRef != NULL) {
        (*headRef)->prev = new_node;
    }
    *headRef = new_node;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = NULL;
    append(&head, 5);
    append(&head, 10);
    append(&head, 15);
    prepend(&head, 1);
    printList(head);
    return 0;
}
