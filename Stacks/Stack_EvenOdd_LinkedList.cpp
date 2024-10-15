#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = nullptr;
        }
};

class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = nullptr;
        }

        bool isEmpty() {
            return top == nullptr;
        }

        void push(int val) {
            Node* newNode = new Node(val);
            newNode->next = top;
            top = newNode;
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return 0;
            } else {
                Node* temp = top;
                int poppedValue = temp->data;
                top = top->next;
                delete temp;

                return poppedValue;
            }
        }

        int sumStack() {
            int sum = 0;
            Node* current = top;
            while (current != nullptr) {
                sum += current->data;
                current = current->next;
            }
            return sum;
        }

        void displayStack() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

int main() {
    Stack evenStack, oddStack;
    int option, value;

    while (true) {
        cout << "Select an Option:" << endl;
        cout << "1) Add value to even Stack" << endl;
        cout << "2) Add value to odd Stack" << endl;
        cout << "3) Display sum of even Stack" << endl;
        cout << "4) Display sum of odd Stack" << endl;
        cout << "5) Display even Stack" << endl;
        cout << "6) Display odd Stack" << endl;
        cout << "7) Exit" << endl;
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter an even number: ";
                cin >> value;
                if (value % 2 == 0) {
                    evenStack.push(value);
                } else {
                    cout << "Invalid input. Please enter an even number." << endl;
                }
                break;

            case 2:
                cout << "Enter an odd number: ";
                cin >> value;
                if (value % 2 != 0) {
                    oddStack.push(value);
                } else {
                    cout << "Invalid input. Please enter an odd number." << endl;
                }
                break;

            case 3:
                cout << "Sum of even Stack: " << evenStack.sumStack() << endl;
                break;

            case 4:
                cout << "Sum of odd Stack: " << oddStack.sumStack() << endl;
                break;

            case 5:
                cout << "Displaying Even Stack: " << endl;
                evenStack.displayStack();
                break;

            case 6:
                cout << "Displaying Odd Stack: " << endl;
                oddStack.displayStack();
                break;

            case 7:
                cout << "Exiting" << endl;
                return 0;

            default:
                cout << "Invalid Option" << endl;
        }
    }
}
