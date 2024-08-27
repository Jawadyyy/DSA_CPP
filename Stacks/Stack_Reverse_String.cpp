#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        int top;
        int ray[100];

    public:
        Stack() {
            top = -1;
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top == 99;
        }

        void push(char val) {
            if(isFull()) {
                cout << "Stack Overflow" << endl;
            } else {
                top++;
                ray[top] = val;
            }
        }

        char pop() {
            if(isEmpty()) {
                cout << "Stack Underflow" << endl;
                return '\0';
            } else {
                char popValue = ray[top];
                top--;
                return popValue;
            }
        }

        void reverse(string &str) {
            for (char ch : str) {
                push(ch);
            }

            for (int i = 0; i < str.length(); i++) {
                str[i] = pop();
            }
        }

};

int main() {

    Stack s;

    string str;

    cout << "Enter the String: " << endl;
    getline(cin, str);

    s.reverse(str);

    cout << "Reversed String: " << str << endl;

    return 0;
}
