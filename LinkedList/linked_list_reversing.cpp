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

void reverseList(Node *&h) {
    Node* previous;
    Node* current;
    Node* next;

    previous = NULL;
    current = h;

    while(current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    h = previous;
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

    cout << "Before Reversing: " << endl;
    printList(head);
    reverseList(head);
    cout << "After Reversing: " <<endl;
    printList(head);

    return 0;
}
