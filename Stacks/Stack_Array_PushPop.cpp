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

};

int main() {

    Stack stack;

    cout << "Pushing values onto the stack:" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "Trying to push one more value (should trigger overflow):" << endl;
    stack.push(60);

    cout << "Popping values from the stack:" << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;

    cout << "Trying to pop from an empty stack (should trigger underflow):" << endl;
    stack.pop();

    return 0;
}