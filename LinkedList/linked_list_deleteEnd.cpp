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

void deleteEnd(Node *h, Node* prev) {
    Node *ptr;

    if(h == NULL) {
        cout << "List is Empty" << endl;
    } else if(h->next == NULL) {
        ptr = h;
        h = NULL;
        free(ptr);
    } else {
        ptr = h;
        while(ptr->next != NULL) {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        free(ptr);
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
    deleteEnd(head,second);
    cout << "The List After Deleting Last Node: " << endl;
    printList(head);


    return 0;
}
