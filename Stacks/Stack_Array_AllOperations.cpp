#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        int top;
        int ray[5];

    public:
        Stack() {
            top = -1;
            for(int i = 0; i<5; i++) {
                ray[i] = 0;
            }
        }

        bool isEmpty() {
            if(top == -1) {
                return true;
            } else {
                return false;
            }
        }

        bool isFull() {
            if(top == 4) {
                return true;
            } else {
                return false; 
            }
        }

        void push(int val) {
            if(isFull()) {
                cout << "Stack Overflow" << endl;
            } else {
                top++;
                ray[top] = val;
            }
        }

        int pop() {
            if(isEmpty()) {
                cout << "Stack Underflow" << endl;
                return 0;
            } else {
                int popValue = ray[top];
                ray[top] = 0;
                top--;
                return popValue;
            }
        }

        int count() {
            return (top+1);
        }

        int peek(int pos) {
            if(isEmpty()) {
                cout << "Stack UnderFlow" <<endl;
                return -1;
            } else {
                return ray[pos];
            }
        }

        void change(int pos, int val) {
            ray[pos] = val;
            cout << "Value chnaged at location" << pos << endl;
        }

        void display() {
            cout << "All values in the Stack are: " << endl;
            for(int i = 4; i>=0; i--) {
                cout << ray[i] << endl;
            }
        }

};

int main() {

    Stack st;
    int option,position,value;

    do {
        cout << "___________________Select an operation_____________________";
        cout << "1. Push a value onto the stack" << endl;
        cout << "2. Pop a value from the stack" << endl;
        cout << "3. Check if the stack is empty" << endl;
        cout << "4. Check if the stack is full" << endl;
        cout << "5. Peek at a specific position" << endl;
        cout << "6. Get the count of items in the stack" << endl;
        cout << "7. Change a value at a specific position" << endl;
        cout << "8. Display all stack values" << endl;
        cout << "9. Clear the screen" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter a value to push: ";
                cin >> value;
                st.push(value);
                break;
            case 2:
                cout << "Popped value: " << st.pop() << endl;
                break;
            case 3:
                if (st.isEmpty())
                    cout << "Stack is empty" << endl;
                else
                    cout << "Stack is not empty" << endl;
                break;
            case 4:
                if (st.isFull())
                    cout << "Stack is full" << endl;
                else
                    cout << "Stack is not full" << endl;
                break;
            case 5:
                cout << "Enter the position to peek at (0-4): ";
                cin >> position;
                cout << "Value at position " << position << ": " << st.peek(position) << endl;
                break;
            case 6:
                cout << "Number of items in the stack: " << st.count() << endl;
                break;
            case 7:
                cout << "Enter the position to change (0-4): ";
                cin >> position;
                cout << "Enter the new value: ";
                cin >> value;
                st.change(position, value);
                break;
            case 8:
                st.display();
                break;
            case 9:
                system("clear"); // Use "cls" for Windows
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