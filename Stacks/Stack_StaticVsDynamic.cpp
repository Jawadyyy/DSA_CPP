#include <iostream>
#include <string>

using namespace std;

class StaticStack {
private:
    int top;
    int ray[5];

public:
    StaticStack() {
        top = -1;
        for (int i = 0; i < 5; i++) {
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
        if (isFull()) {
            cout << "Static Stack Overflow" << endl;
        } else {
            top++;
            ray[top] = val;
        }
    }

    int pop() {
        if (isEmpty()) {
            cout << "Static Stack Underflow" << endl;
            return 0;
        } else {
            int popValue = ray[top];
            ray[top] = 0;
            top--;
            return popValue;
        }
    }

    void display() {
        cout << "All values in the Static Stack are: " << endl;
        for (int i = 4; i >= 0; i--) {
            cout << ray[i] << endl;
        }
    }
};

class DynamicStack {
private:
    int top;
    int capacity;
    int* array;

public:
    DynamicStack(int size = 5) {
        top = -1;
        capacity = size;
        array = new int[capacity];
    }

    ~DynamicStack() {
        delete[] array;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void resize() {
        capacity *= 2;
        int* newArray = new int[capacity];
        for (int i = 0; i <= top; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Dynamic Stack Resizing..." << endl;
            resize();
        }
        top++;
        array[top] = val;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Dynamic Stack Underflow" << endl;
            return 0;
        } else {
            int popValue = array[top];
            array[top] = 0;
            top--;
            return popValue;
        }
    }

    void display() {
        cout << "All values in the Dynamic Stack are: " << endl;
        for (int i = top; i >= 0; i--) {
            cout << array[i] << endl;
        }
    }
};

int main() {
    int option, value;
    
    StaticStack staticStack;
    DynamicStack dynamicStack;

    do {
        cout << "___________________Select an operation_____________________" << endl;
        cout << "1. Push to Static Stack" << endl;
        cout << "2. Pop from Static Stack" << endl;
        cout << "3. Display Static Stack" << endl;
        cout << "4. Push to Dynamic Stack" << endl;
        cout << "5. Pop from Dynamic Stack" << endl;
        cout << "6. Display Dynamic Stack" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter value to push onto Static Stack: ";
                cin >> value;
                staticStack.push(value);
                break;
            case 2:
                cout << "Popped value from Static Stack: " << staticStack.pop() << endl;
                break;
            case 3:
                staticStack.display();
                break;
            case 4:
                cout << "Enter value to push onto Dynamic Stack: ";
                cin >> value;
                dynamicStack.push(value);
                break;
            case 5:
                cout << "Popped value from Dynamic Stack: " << dynamicStack.pop() << endl;
                break;
            case 6:
                dynamicStack.display();
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
