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

void findMidNode(Node* h) {
    Node* slow = h;
    Node* fast = h;

    if(h == NULL) {
        cout << "List is Empty" << endl;
    } else {
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
    }

    cout << "Middle Node is: " << slow->value << endl;
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
    Node *fourth = new Node(15);

    head->next = second;

    second->next = third;

    third->next = fourth;

    fourth->next = NULL;

    cout << "The List: " << endl;
    printList(head);
    findMidNode(head);

    return 0;
}
