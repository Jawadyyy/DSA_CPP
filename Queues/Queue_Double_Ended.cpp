#include <iostream>
using namespace std;

class Deque
{
private:
    int ray[5];
    int front;
    int back;
    int size;

public:
    Deque()
    {
        front = -1;
        back = -1;
        size = 5;
    }

    void enqueueFront(int x)
    {
        if (front == 0 && back == size - 1 || front == back + 1)
        {
            cout << "Deque overflow" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
            back = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }
        ray[front] = x;
    }

    void enqueueBack(int x)
    {
        if (front == 0 && back == size - 1 || front == back + 1)
        {
            cout << "Deque overflow" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
            back = 0;
        }
        else if (back == size - 1)
        {
            back = 0;
        }
        else
        {
            back++;
        }
        ray[back] = x;
    }

    void dequeueFront()
    {
        if (front == -1)
        {
            cout << "Deque underflow" << endl;
            return;
        }

        cout << "Dequeued from front: " << ray[front] << endl;

        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void dequeueBack()
    {
        if (back == -1)
        {
            cout << "Deque underflow" << endl;
            return;
        }

        cout << "Dequeued from back: " << ray[back] << endl;

        if (front == back)
        {
            front = -1;
            back = -1;
        }
        else if (back == 0)
        {
            back = size - 1;
        }
        else
        {
            back--;
        }
    }

    int peekFront()
    {
        if (front == -1)
        {
            cout << "Deque underflow" << endl;
            return -1;
        }
        return ray[front];
    }

    int peekBack()
    {
        if (back == -1)
        {
            cout << "Deque underflow" << endl;
            return -1;
        }
        return ray[back];
    }

    bool empty()
    {
        return front == -1;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Deque is empty" << endl;
            return;
        }

        cout << "Deque elements: ";
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
    Deque dq;

    dq.enqueueBack(10);
    dq.enqueueBack(20);
    dq.enqueueFront(30);
    dq.enqueueFront(40);
    dq.display();

    dq.dequeueFront();
    dq.dequeueBack();
    dq.display();

    cout << "Front element: " << dq.peekFront() << endl;
    cout << "Back element: " << dq.peekBack() << endl;

    return 0;
}
