#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = NULL;
        }
};

class Queue {
    private:
        Node* front;
        Node* back;
    public:
        Queue() {
            front = NULL;
            back = NULL;
        }

        void push(int x) {
            Node* n = new Node(x);

            if(front == NULL) {
                front = n;
                back = n;
            } else {
                back->next = n;
                back = n;
            }
        }

        void pop() {
            if(front == NULL) {
                cout << "Queue Underflow" << endl;
                return;
            }

            Node* todelete = front;
            front = front->next;

            delete todelete;
        }

        int peek() {
            if(front == NULL) {
                cout << "No element in Queue" << endl;
                return -1;
            }

            return front->data;
        }

        bool empty() {
            return front == NULL;
        }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front element: " << q.peek() << endl;

    q.pop();
    cout << "Front element after pop: " << q.peek() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "Is queue empty? " << q.empty() << endl;

    return 0;
}
