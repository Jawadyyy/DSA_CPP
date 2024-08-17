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

void printNode(Node *h, int i) {
    if(h == NULL || i < 0) {
        return;
    }
    if(i == 0) {
        cout << h->value;
        return;
    }
    printNode(h->next, i-1);
}

int main() {

    // Initialize nodes
    Node *head = new Node(3);
    Node *second = new Node(18);
    Node *third = new Node(26);
    Node *fourth = new Node(4);

    // Linking Nodes
    head->next = second;

    second->next = third;

    third->next = fourth;

    fourth->next = NULL;
    
    printNode(head,2);

    return 0;

}