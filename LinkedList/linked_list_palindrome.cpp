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

// Function to print the linked list
void printList(Node *head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }

    Node *current = head;
    while (current != NULL) {
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

Node* reverseList(Node *&h) {
    Node* previous;
    Node* current;
    Node* next;

    previous = NULL;
    current = h;

    while(current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

bool isPalindrome(Node *head) {
    if (head == NULL || head->next == NULL) return true;

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHalf = reverseList(slow);
    Node *firstHalf = head;

    while (secondHalf != NULL) {
        if (firstHalf->value != secondHalf->value) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
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

    cout << "Linked list: ";
    printList(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
