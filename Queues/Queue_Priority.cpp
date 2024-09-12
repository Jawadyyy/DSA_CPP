#include <iostream>
using namespace std;

class PriorityQueue {
    private:
        int ray[5];
        int size;

    public:
        PriorityQueue() {
            size = 0;
            for (int i = 0; i < 5; i++) {
                ray[i] = 0;
            }
        }

        bool isFull() {
            return size == 5;
        }

        bool isEmpty() {
            return size == 0;
        }

        void enqueue(int val) {
            if (isFull()) {
                cout << "Queue Overflow" << endl;
                return;
            }

            int i;
            for (i = size - 1; i >= 0 && ray[i] > val; i--) {
                ray[i + 1] = ray[i];
            }
            ray[i + 1] = val;
            size++;
        }

        int dequeue() {
            if (isEmpty()) {
                cout << "Queue Underflow" << endl;
                return -1;
            }

            int frontValue = ray[0];
            for (int i = 0; i < size - 1; i++) {
                ray[i] = ray[i + 1];
            }
            size--;
            return frontValue;
        }

        void display() {
            if (isEmpty()) {
                cout << "Queue is Empty" << endl;
                return;
            }

            cout << "Elements in the Priority Queue: ";
            for (int i = 0; i < size; i++) {
                cout << ray[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(50);
    pq.enqueue(20);
    pq.enqueue(40);

    pq.display();

    cout << "Dequeue: " << pq.dequeue() << endl;
    pq.display();

    return 0;
}
