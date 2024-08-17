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

int findElements(Node *h) {
    int count = 0;
    while(h !=NULL) {
        h = h->next;
        count++;
    }

    cout << "Total Nodes In this List are: " << count << endl;
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
    findElements(head);


    return 0;
}
