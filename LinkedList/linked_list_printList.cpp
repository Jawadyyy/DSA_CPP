#include <iostream>

using namespace std;

class Node {
public:
    Node *next;
    int value;
};

void printList(Node *n) {
    while (n != NULL) {
        cout << n->value << endl;
        n = n->next;
    }
}

int main() {

    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->value = 1;
    head->next = second;

    second->value = 2;
    second->next = third;

    third->value = 3;
    third->next = fourth;

    fourth->value = 4;
    fourth->next = NULL;

    printList(head);
    
    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
