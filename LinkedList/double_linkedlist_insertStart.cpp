#include <iostream>
using namespace std;

class Node
{
private:
    string value;
    Node *next;
    Node *prev;

public:
    Node(string val) {
        this->value = val;    
        next = NULL;
        prev = NULL;
    }

    void printListForward(Node *n)
    {
        while (n != NULL)
        {
            cout << n->value << " ";
            n = n->next;
        }
        cout << endl;
    }

    void printListBackward(Node *n)
    {
        while (n != NULL)
        {
            cout << n->value << " ";
            n = n->prev;
        }
        cout << endl;
    }

    void append_data(Node **head, string data) {
        Node* newNode = new Node(data);
        newNode->next = *head;
        newNode->prev = NULL;

        if(*head != NULL) {
            (*head)->prev = newNode;
        }

        *head = newNode;
    }

    Node* getLastNode(Node *n) {
        while (n->next != NULL) {
            n = n->next;
        }
        return n;
    }
};

int main()
{
    Node *head = NULL;
    Node obj("");

    obj.append_data(&head, "Red");
    obj.append_data(&head, "Green");
    obj.append_data(&head, "White");
    obj.append_data(&head, "Orange");

    cout << "Forward: ";
    obj.printListForward(head);

    Node *last = obj.getLastNode(head);
    cout << "Backward: ";
    obj.printListBackward(last);

    return 0;
}
