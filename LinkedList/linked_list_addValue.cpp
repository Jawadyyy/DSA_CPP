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
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Node *current = head;
    while (current != NULL) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

void deleteList(Node* &head) {
    if (head == NULL) return;

    Node *current = head;
    Node *nextNode;

    while (current != NULL) {
        nextNode = current->next; 
        delete current; 
        current = nextNode;     
    }
    
    head = NULL;
}

int sumOfNodes(Node *head) {
    int totalSum = 0;
    Node *current = head;

    while (current != NULL) {
        totalSum += current->value;
        current = current->next;
    }

    return totalSum;
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

    cout << "Linked list: ";
    printList(head);

    int totalSum = sumOfNodes(head);
    cout << "Sum of all node values: " << totalSum << endl;

    deleteList(head);

    if (head == NULL) {
        cout << "The linked list has been deleted." << endl;
    }

    return 0;
}
