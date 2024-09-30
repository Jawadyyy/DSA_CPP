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
                ray[top] = 0;
                top--;
                return popValue;
            }
        }

        bool checkPalindrome(int n) {
            int original = n;
            int reverse = 0, factor = 1;

            while(n > 0) {
                push(n % 10);
                n = n / 10;
            }

            while(!isEmpty()) {
                reverse = reverse + pop() * factor;
                factor *= 10;
            }

            return (original == reverse);
        }
};

int main() {
    Stack st;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if(st.checkPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    return 0;
}
