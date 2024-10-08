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
};

int main() {
    Stack s;
    int position;

    position = 0;
    cout << "Peeking at position " << position << ": " << s.peek(position) << endl;

    cout << "Current stack count: " << s.count() << endl;

    return 0;
}
