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