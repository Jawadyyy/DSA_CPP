#include <iostream>
using namespace std;

class Queue
{
private:
    int ray[5];
    int front;
    int back;

public:
    Queue()
    {
        front = -1;
        back = -1;
    }

    void enqueue(int x)
    {
        if (back == 4)
        {
            cout << "Queue overflow" << endl;
            return;
        }

        if (front == -1)
        {
            front++;
        }

        back++;
        ray[back] = x;
    }

    void dequeue()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue underflow" << endl;
            return;
        }

        cout << "Dequeued: " << ray[front] << endl;
        front++;
    }

    int peek() {

        if (front == -1 || front > back)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        return ray[front];

    }

    bool empty() {

         if (front == -1 || front > back)
        {
            return true;
        }
    }

    void display()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= back; i++)
        {
            cout << ray[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display(); 

    q.enqueue(60); 

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.dequeue(); 
    q.display();

    while (!q.empty())
    {
        q.dequeue();
    }

    q.display(); 

    q.dequeue(); 

    cout << "Front element: " << q.peek() << endl;

    return 0;
}
