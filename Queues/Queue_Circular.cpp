#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int ray[5];
    int front;
    int back;
    int size;

public:
    CircularQueue()
    {
        front = -1;
        back = -1;
        size = 5;
    }

    void enqueue(int x)
    {
        if ((back + 1) % size == front)
        {
            cout << "Queue overflow" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        back = (back + 1) % size;
        ray[back] = x;
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return;
        }

        cout << "Dequeued: " << ray[front] << endl;

        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    int peek()
    {
        if (front == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        return ray[front];
    }

    bool empty()
    {
        return front == -1;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true)
        {
            cout << ray[i] << " ";
            if (i == back)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q;

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
