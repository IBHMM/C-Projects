#include <iostream>
#include <string>
using namespace std;

class Cell{
    public:
        int data;
        Cell* next;
};

void add_element(Cell** sentinal, int value){
    Cell* t_sentinal = *sentinal;
    Cell* new_cell = new Cell();
    new_cell->next = NULL;
    new_cell->data = value;

    if(t_sentinal->next == nullptr) {
        t_sentinal->next = new_cell;
        return;
    }
    Cell* head = t_sentinal->next;

    while(head->next != nullptr){
        head = head->next;
    }

    head->next = new_cell;
    
}

void print(Cell** sentinal){
    Cell* t_sentinal = *sentinal;
    if(t_sentinal->next == nullptr){
        cout << "list is empty" << endl;
        return;
    }
    Cell* head = t_sentinal->next;

    while(head != nullptr){
        cout << head->data << "->";
        head = head->next;
    }
}

void sort(Cell** sentinel) {
    Cell* t_sentinel = *sentinel;
    if (t_sentinel->next == nullptr || t_sentinel->next->next == nullptr) {
        return;
    }

    Cell* current = t_sentinel->next->next;
    Cell* lastSorted = t_sentinel->next;

    while (current != nullptr) {
        Cell* innerCurrent = t_sentinel;
        while (innerCurrent != current) {
            if (innerCurrent->next->data > current->data) {
                lastSorted->next = current->next;
                current->next = innerCurrent->next;
                innerCurrent->next = current;
                break;
            }
            innerCurrent = innerCurrent->next;
        }
        if (innerCurrent == current) {
            lastSorted = current;
        }
        current = lastSorted->next;
    }
}



int main () {

    cout << "Enter the List (type end if finished) : " << endl;

    Cell* sentinal = new Cell();
    sentinal->next = nullptr;

    int input;
    cout << "Input: ";
    cin >> input;

    while(input != 0){
        add_element(&sentinal, input);
        cout << "Input: ";
        cin >> input;
    }

    sort(&sentinal);

    print(&sentinal);

}