#include <iostream>

using namespace std;

class Stack {
    private:
        int top;
        int ray[5];

    public:
        Stack() {
            top = -1;
            for(int i = 0; i < 5; i++) {
                ray[i] = 0;
            }
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == 4;
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
                top--;
                return popValue;
            }
        }

        int peek() {
            if(isEmpty()) {
                cout << "Stack Underflow" << endl;
                return 0;
            } else {
                return ray[top];
            }
        }

        int count() {
            return (top + 1);
        }

        void change(int pos, int val) {
            ray[pos] = val;
            cout << "Value changed at location " << pos << endl;
        }

        void display() {
            cout << "All values in the Stack are: " << endl;
            for(int i = top; i >= 0; i--) {
                cout << ray[i] << endl;
            }
        }
};

class Queue {
    private:
        Stack stack1;
        Stack stack2;

    public:
        void push(int x) {
            stack1.push(x);
        }

        int pop() {
            if(stack1.isEmpty() && stack2.isEmpty()) {
                cout << "Queue is Empty" << endl;
                return -1;
            }
            if(stack2.isEmpty()) {
                while(!stack1.isEmpty()) {
                    stack2.push(stack1.pop());
                }
            }
            return stack2.pop();
        }

        bool emptyy() {
            return stack1.isEmpty() && stack2.isEmpty();
        }

        void reverse() {
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
            while (!stack2.isEmpty()) {
                stack1.push(stack2.pop());
            }
        }

        void displayQueue() {
            cout << "Queue elements are: ";
            while (!stack1.isEmpty()) {
                stack2.push(stack1.pop());
            }
            while (!stack2.isEmpty()) {
                int val = stack2.pop();
                cout << val << " ";
                stack1.push(val);
            }
            cout << endl;
        }
};

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original Queue: ";
    q.displayQueue();

    q.reverse();

    cout << "Reversed Queue: ";
    q.displayQueue();

    return 0;
}
