#include <iostream>

class Node {
    public:
        int data;
        Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void insertionSort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* sorted = nullptr;
        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;

            if (sorted == nullptr || sorted->data >= current->data) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* search = sorted;
                while (search->next != nullptr && search->next->data < current->data) {
                    search = search->next;
                }
                current->next = search->next;
                search->next = current;
            }
            current = next;
        }
        head = sorted;
    }
};

int main() {
    LinkedList list;
    list.insert(3);
    list.insert(5);
    list.insert(1);
    list.insert(4);

    std::cout << "Original list: ";
    list.printList();

    list.insertionSort();

    std::cout << "Sorted list: ";
    list.printList();

    return 0;
}
