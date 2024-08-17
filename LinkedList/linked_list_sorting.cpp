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

void sorted(Node* head) {
    int num;
    Node *i;
    Node *j;

    for(i = head; i->next != NULL; i=i->next) {
        for(j=i->next; j != NULL; j=j->next) {
            if(i->value > j->value) {
                num = j->value;
                j->value = i->value;
                i->value = num;
            }
        }
    }
}

void printList(Node *n) {
    while (n != NULL) {
        cout << n->value << endl;
        n = n->next;
    }
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
    
    printList(head);
    sorted(head);
    cout<< "After Sorting" <<endl;
    printList(head);

    // Clear Memory

    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;

}