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

    void append_data(Node **head, string data)
    {
        Node *newNode = new Node(data);
        if (*head == NULL)
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            *head = newNode;
            return;
        }

        Node *last = (*head)->prev;
        newNode->next = *head;
        (*head)->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
    }

    void splitList(Node *head, Node **first_half, Node **second_half)
    {
        if (head == NULL || head->next == head)
        {
            *first_half = head;
            *second_half = NULL;
            return;
        }

        Node *slow = head;
        Node *fast = head;

        while (fast->next != head && fast->next->next != head)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast->next->next == head)
        {
            fast = fast->next;
        }

        *first_half = head;
        *second_half = slow->next;

        slow->next = *first_half;
        (*first_half)->prev = slow;

        fast->next = *second_half;
        (*second_half)->prev = fast;
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

    Node *first_half = NULL;
    Node *second_half = NULL;

    obj.splitList(head, &first_half, &second_half);

    cout << "First half: ";
    obj.printListForward(first_half);
    
    cout << "Second half: ";
    obj.printListForward(second_half);

    return 0;
}
