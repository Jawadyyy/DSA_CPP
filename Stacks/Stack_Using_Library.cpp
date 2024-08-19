#include <iostream>
#include <stack>

using namespace std;

void printStackElements(stack<int> stack) {
    while (!stack.empty()) {
        cout << stack.top() <<endl;
        stack.pop();
    }
}

int main() {

    stack<int>numbersStack;
    numbersStack.push(1);
    numbersStack.push(2);
    numbersStack.push(3);


    printStackElements(numbersStack);

    /*if(numbersStack.empty()) {
        cout << "My Stack is Empty" << endl;
    } else {
        cout << "My Stack is not Empty" << endl;
    }

    cout << "Stack size is: " << numbersStack.size() << endl;*/

    return 0;
}