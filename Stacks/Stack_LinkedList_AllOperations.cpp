#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        int key;
        Node* next;

        Node() {
            key = 0;
            data = 0;
            next = NULL;
        }

        Node(int k, int d) {
            key = k;
            data = d;
            next = NULL;
        }
};

class Stack {
    public:
        Node* top;

        Stack() {
            top = NULL;
        }

        bool checkIfNodeExists(Node *n) {
            Node *temp = top;
            while (temp != NULL) {
                if (temp->key == n->key) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        bool isEmpty() {
            return top == NULL;
        }

        void push(Node *n) {
            if (checkIfNodeExists(n)) {
                cout << "Node already exists with key value: " << n->key << ". Enter a different key value." << endl;
            } else {
                n->next = top;
                top = n;
                cout << "Node pushed successfully." << endl;
            }
        }

        Node* pop() {
            if (isEmpty()) {
                cout << "Stack underflow." << endl;
                return NULL;
            } else {
                Node *temp = top;
                top = top->next;
                return temp;
            }
        }

        Node* peek() {
            if (isEmpty()) {
                cout << "Stack underflow." << endl;
                return NULL;
            } else {
                return top;
            }
        }

        int count() {
            int count = 0;
            Node *temp = top;
            while (temp != NULL) {
                count++;
                temp = temp->next;
            }
            return count;
        }

        void display() {
            if (isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "All values in the stack are:" << endl;
                Node *temp = top;
                while (temp != NULL) {
                    cout << "(" << temp->key << ", " << temp->data << ") -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;
            }
        }
};

int main() {
    Stack st;
    int option, key, data;

    do {
        cout << "___________________Select an operation_____________________" << endl;
        cout << "1. Push a value onto the stack" << endl;
        cout << "2. Pop a value from the stack" << endl;
        cout << "3. Check if the stack is empty" << endl;
        cout << "4. Peek at the top value of the stack" << endl;
        cout << "5. Get the count of items in the stack" << endl;
        cout << "6. Display all stack values" << endl;
        cout << "7. Clear the screen" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        Node* new_node = new Node();

        switch (option) {
            case 1:
                cout << "Enter key and value to push: ";
                cin >> key >> data;
                new_node->key = key;
                new_node->data = data;
                st.push(new_node);
                break;
            case 2:
                cout << "Popped value: (" << st.pop()->key << ", " << st.pop()->data << ")" << endl;
                break;
            case 3:
                if (st.isEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is not empty" << endl;
                break;
            case 4:
                if (!st.isEmpty()) {
                    Node* peek_node = st.peek();
                    cout << "Top value: (" << peek_node->key << ", " << peek_node->data << ")" << endl;
                }
                break;
            case 5:
                cout << "Number of items in the stack: " << st.count() << endl;
                break;
            case 6:
                st.display();
                break;
            case 7:
                system("clear");
                break;
            case 0:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
        }

    } while (option != 0);

    return 0;
}
