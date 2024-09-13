#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node *next;
    Node *prev;
};

void printListForward(Node *n) {
    while (n != NULL) {
        cout << n->value << " ";
        n = n->next;
    }
    cout << endl;
}

void printListBackward(Node *n) {
    while (n != NULL) {
        cout << n->value << " ";
        n = n->prev;
    }
    cout << endl;
}

int main() {
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->value = 1;
    head->next = second;
    head->prev = NULL;

    second->value = 2;
    second->next = third;
    second->prev = head;

    third->value = 3;
    third->next = fourth;
    third->prev = second;

    fourth->value = 4;
    fourth->next = NULL; 
    fourth->prev = third;

    // Print list forward
    cout << "Forward: ";
    printListForward(head);

    cout << "Backward: ";
    printListBackward(fourth);

    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
