#include <iostream>
using namespace std;

class Queue
{
private:
    int ray[100]; 
    int front;
    int back; 

public:
    Queue() {
        front = -1;
        back = -1;
    }

    void enqueue(int x) {
        if (back == 99) {
            cout << "Queue overflow" << endl;
            return;
        }

        if (front == -1) {
            front++;
        }

        back++;
        ray[back] = x;
    }

    void dequeue() {
        if (front == -1 || front > back) {
            cout << "Queue underflow" << endl;
            return;
        }

        front++;
    }

    int peek() {
        if (front == -1 || front > back) {
            return -1;
        }

        return ray[front];
    }

    bool empty() {
        return (front == -1 || front > back);
    }

    bool isPalindrome(int number) {
        int original = number;
        int reverseNumber = 0;
        
        while (number > 0) {
            int digit = number % 10;
            enqueue(digit);
            number /= 10;
        }
        
        int power = 1;
        
        while (!empty()) {
            reverseNumber += peek() * power;
            power *= 10;
            dequeue();
        }

        return (original == reverseNumber);
    }
};

int main()
{
    Queue q;
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (q.isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
