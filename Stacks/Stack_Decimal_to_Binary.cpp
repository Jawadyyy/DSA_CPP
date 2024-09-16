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
                return -1;
            } else {
                int popValue = ray[top];
                ray[top] = 0;
                top--;
                return popValue;
            }
        }
        
        void binaryConversion(int num) {
            while(num > 0) {
                int remainder = num % 2;
                push(remainder);
                num = num / 2;
            }

            cout << "Binary Representation: ";
            while(!isEmpty()) {
                cout << pop(); 
            }
            cout << endl;
        }
};

int main() {
    Stack st;
    int number;

    cout << "Enter a number to convert to binary: ";
    cin >> number;

    st.binaryConversion(number);

    return 0;
}
