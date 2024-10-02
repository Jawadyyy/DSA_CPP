#include <iostream>
using namespace std;

class Stack {
    private:
        int top;
        int* ray;
        int size;

    public:
        Stack(int s) {
            size = s;
            top = -1;
            ray = new int[size]; 
            for(int i = 0; i < size; i++) {
                ray[i] = 0;
            }
        }

        ~Stack() {
            delete[] ray;
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == size - 1;
        }

        void push(int val) {
            if (isFull()) {
                cout << "Stack Overflow" << endl;
            } else {
                top++;
                ray[top] = val;
            }
        }

        int pop() {
            if (isEmpty()) {
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
            return top + 1;
        }

        int peek(int pos) {
            if (isEmpty()) {
                cout << "Stack UnderFlow" << endl;
                return -1;
            } else if (pos < 0 || pos > top) {
                cout << "Invalid position" << endl;
                return -1;
            } else {
                return ray[pos];
            }
        }

        void change(int pos, int val) {
            if (pos < 0 || pos > top) {
                cout << "Invalid position" << endl;
            } else {
                ray[pos] = val;
                cout << "Value changed at location " << pos << endl;
            }
        }

        void display() {
            cout << "All values in the Stack are: " << endl;
            for (int i = top; i >= 0; i--) {
                cout << ray[i] << endl;
            }
        }
};

int main() {
    int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;

    Stack st(stackSize);
    int option, position, value;

    do {
        cout << "___________________Select an operation_____________________" << endl;
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
                cout << "Enter the position to peek at (0-" << stackSize - 1 << "): ";
                cin >> position;
                cout << "Value at position " << position << ": " << st.peek(position) << endl;
                break;
            case 6:
                cout << "Number of items in the stack: " << st.count() << endl;
                break;
            case 7:
                cout << "Enter the position to change (0-" << stackSize - 1 << "): ";
                cin >> position;
                cout << "Enter the new value: ";
                cin >> value;
                st.change(position, value);
                break;
            case 8:
                st.display();
                break;
            case 9:
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
