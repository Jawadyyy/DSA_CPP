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

void printList(Node *n) {
    while (n != NULL) {
        cout << n->value << endl;
        n = n->next;
    }
}

void deleteList(Node* &head) {
    Node *current = head;
    while (current != NULL) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = NULL;
}

void sorted(Node* head) {
    int num;
    Node *i;
    Node *j;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->value > j->value) {
                num = j->value;
                j->value = i->value;
                i->value = num;
            }
        }
    }
}

void removeDuplicates(Node* head) {
    if (head == NULL) return;

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->value == current->next->value) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next; 
        }
    }
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

    cout << "Original linked list: " << endl;
    printList(head);

    sorted(head);

    cout << "Sorted linked list: " << endl;
    printList(head);

    removeDuplicates(head);

    cout << "Linked list after removing duplicates: " << endl;
    printList(head);

    return 0;
}
