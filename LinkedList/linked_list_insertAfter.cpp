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

void insertAfter(Node *previous, int val) {
    //Check if previous Node is Null
    if(previous == NULL) {
        cout << "Previous Node cannot be NULL. Try again!!" <<endl;
        return;
    }

    //Prepare a new Node
    Node* newNode = new Node(val);

    //Insert new Node after previous
    newNode->next = previous->next;
    previous->next = newNode;
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
    insertAfter(head,22);
    cout << "The List After inserting at End: " << endl;
    printList(head);


    return 0;
}
