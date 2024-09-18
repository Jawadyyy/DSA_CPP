#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = NULL;
    }
};

void printList(Node *head) {
    if (head == NULL) return;
    Node *current = head;
    
    do {
        cout << current->value << endl;
        current = current->next;
    } while (current != head);
}

void deleteList(Node* &head) {
    if (head == NULL) return;

    Node *current = head;
    Node *nextNode = NULL;

    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
    
    head = NULL;
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    Node *head = NULL;
    Node *tail = NULL;

    for (int i = 1; i <= n; i++) {
        int val;
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        
        Node *newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    if (tail != NULL) {
        tail->next = head; 
    }

    cout << "The cyclic linked list is: " << endl;
    printList(head);

    deleteList(head);

    if (head == NULL) {
        cout << "The cyclic linked list has been deleted." << endl;
    }

    return 0;
}
