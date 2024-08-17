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

void insertStart(Node **h, int val) {
    // Prepare a newNode
    Node *newNode = new Node(val);
    // Put it in front of current head
    newNode->next = *h;
    // Move head of the list to point to the newNode
    *h = newNode;
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
    insertStart(&head,2);
    cout << "The List After inserting at Start: " << endl;
    printList(head);


    return 0;
}
