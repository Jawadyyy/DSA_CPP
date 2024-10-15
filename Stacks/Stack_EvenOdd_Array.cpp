#include <iostream>
#include <string>

using namespace std;

const int size = 10;

class Stack {
    private:
        int top;
        int *ray;

    public:
        Stack() {
            top = -1;
            ray = new int[size];
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == size-1;
        }

        int stackSize() {
            return top + 1;
        }

        void push(int val) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
            } else {
                ray[++top] = val;
            }
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack Underflow" << endl;
                return 0;
            } else {
                return ray[top--];
            }
        }

        void displayStack() {
            for(int i=top; i>=0; i--) {
                cout << ray[i] << " " ;
            }
            cout << endl;
        }

        int sumStack() {
            int sum = 0;
            for (int i = 0; i <= top; i++) {
                sum += ray[i];
            }
            return sum;
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
