Node* pack_primes(Node** head) {
    // Check if the list is empty
    if (*head == nullptr) {
        cout << "List is empty" << endl;
        return NULL;
    }

    // Initialize pointers for the original list and the new list
    Node* thead = *head; // Pointer to the current node in the original list
    Node* new_head = nullptr; // Pointer to the head of the new list
    Node* current = nullptr; // Pointer to the current node in the new list

    // Loop through the original list
    while (thead) {
        bool found = false;
        // Check if the current value exists in the new list
        for (Node* node = new_head; node; node = node->next) {
            // If the value exists, increment the count and set found to true
            if (node->value == thead->value) {
                node->count++;
                found = true;
                break;
            }
        }
        // If the value doesn't exist, create a new node and add it to the new list
        if (!found) {
            Node* new_node = new Node{thead->value, 1, nullptr}; // Create a new node with the current value and count set to 1
            if (!new_head) 
                new_head = current = new_node; // If the new list is empty, set the new node as the head of the new list
            else 
                current = current->next = new_node; // Otherwise, add the new node to the end of the new list
        }
        // Move to the next node in the original list
        thead = thead->next;
    }

    // Print the new list with counted prime numbers
    while (new_head) {
        if(new_head->next != NULL){
            cout << (new_head->next ? "{ " + to_string(new_head->value) + "," + to_string(new_head->count) + " }   " : "{ " + to_string(new_head->value) + "," + to_string(new_head->count) + " }");
        }
        new_head = new_head->next; // Move to the next node in the new list
    }
    return new_head; // Return the head of the new list
}
