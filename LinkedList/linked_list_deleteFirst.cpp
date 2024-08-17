#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = NULL;
    }
};

void deleteFirst(Node **h) {
    
    if(h == NULL) {
        cout<< "List is Empty" << endl;
    } else {
        Node *ptr = *h;
        *h = (*h)->next;
        free(ptr);
    }
}

void printList(Node *n) {
    while (n != NULL) {
        cout << n->value << endl;
        n = n->next;
    }
}

int main() {

    Node *head = new Node(5);
    Node *second = new Node(12);
    Node *third = new Node(9);

    head->next = second;

    second->next = third;

    third->next = NULL;

    cout << "The List: " << endl;
    printList(head);
    deleteFirst(&head);
    cout << "The List After Deleting First Node: " << endl;
    printList(head);


    return 0;
}
