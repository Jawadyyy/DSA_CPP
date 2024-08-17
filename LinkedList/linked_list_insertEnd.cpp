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

void insertEnd(Node **h, int val) {
    // Prepare a newNode
    Node *newNode = new Node(val);
    newNode->next = NULL;

    // If the linked list is empty, newNode will be the head node
    if (*h == NULL) {
        *h = newNode;
        return;
    }

    // Find the last node
    Node *last = *h;
    while (last->next != NULL) {
        last = last->next;
    }

    // Insert newNode after the last node (at the end so it becomes the tail node)
    last->next = newNode;
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
    insertEnd(&head,22);
    cout << "The List After inserting at End: " << endl;
    printList(head);


    return 0;
}
