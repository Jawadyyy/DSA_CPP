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

void printList(Node *n) {
    while (n != NULL) {
        cout << n->value << endl;
        n = n->next;
    }
}

Node* takeInput() {
    int data;
    cin >> data;

    Node* head = NULL;
    Node* tail = NULL;

    while (data != -1) { 
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }

    return head;
}

int main() {
    Node* head = takeInput();
    printList(head);
    return 0;
}
