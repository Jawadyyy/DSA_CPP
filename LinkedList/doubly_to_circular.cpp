#include <iostream>
using namespace std;

class Node
{
private:
    string value;
    Node *next;
    Node *prev;

public:
    Node(string val)
    {
        this->value = val;
        next = NULL;
        prev = NULL;
    }

    void printListForward(Node *n)
    {
        if (n == NULL)
            return;

        Node *start = n;
        do
        {
            cout << n->value << " ";
            n = n->next;
        } while (n != start);
        cout << endl;
    }

    void printListBackward(Node *n)
    {
        if (n == NULL)
            return;

        Node *start = n;
        do
        {
            cout << n->value << " ";
            n = n->prev;
        } while (n != start);
        cout << endl;
    }

    void append_data(Node **head, string data)
    {
        Node *newNode = new Node(data);
        newNode->next = *head;

        if (*head != NULL)
        {
            newNode->prev = (*head)->prev;
            (*head)->prev = newNode;
        }
        else
        {
            newNode->prev = newNode;
        }

        if (newNode->prev != NULL)
        {
            newNode->prev->next = newNode;
        }

        *head = newNode;
    }

    void convertToCircular(Node **head)
    {
        if (*head == NULL)
            return;

        Node *last = (*head)->prev; 
        if (last != NULL)
        {
            last->next = *head;  
            (*head)->prev = last; 
        }
    }

    Node *getLastNode(Node *n)
    {
        return n->prev;
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

    obj.convertToCircular(&head);

    cout << "Forward (Circular): ";
    obj.printListForward(head);

    Node *last = obj.getLastNode(head);
    cout << "Backward (Circular): ";
    obj.printListBackward(last);

    return 0;
}
