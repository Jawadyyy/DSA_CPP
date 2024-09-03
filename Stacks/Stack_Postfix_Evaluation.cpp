#include <iostream>
#include <string>
#include <cmath> // Include for pow function

using namespace std;

class Stack
{
private:
    int top;
    int ray[5];

public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++)
        {
            ray[i] = 0;
        }
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == 4;
    }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            ray[top] = val;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        else
        {
            int popValue = ray[top];
            ray[top] = 0;
            top--;
            return popValue;
        }
    }

    int postfixEvaluation(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                push(s[i] - '0');
            }
            else
            {
                int op2 = pop();
                int op1 = pop();

                switch (s[i])
                {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '^':
                    push(pow(op1, op2));
                    break;
                }
            }
        }
        return pop();
    }
};

int main()
{
    Stack st;
    cout << "Result: " << st.postfixEvaluation("46+2/5*7+") << endl;
    return 0;
}