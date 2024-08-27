#include <iostream>
#include <string>

using namespace std;

class Stack {
    private:
        int top;
        char ray[100];

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

        bool isValid(string s) {
            int n = s.size();
            bool ans = true;

            for (int i = 0; i < n; i++) {
                if(s[i] == '{' || s[i] == '(' || s[i] == '[' ) {
                    push(s[i]);
                }
                else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                    if(isEmpty()) {
                        ans = false;
                        break;
                    }
                    char topChar = pop();
                    if((s[i] == ')' && topChar != '(') ||
                       (s[i] == ']' && topChar != '[') ||
                       (s[i] == '}' && topChar != '{')) {
                        ans = false;
                        break;
                    }
                }
            }

            if(!isEmpty()) ans = false;

            return ans;
        }
};

int main() {
    string s;
    Stack stack;

    cout << "Enter String to check Valid Parenthesis: " << endl;
    getline(cin, s);

    if(stack.isValid(s)) {
        cout << "Valid String" << endl;
    } else {
        cout << "Invalid String" << endl;
    }

    return 0;
}
