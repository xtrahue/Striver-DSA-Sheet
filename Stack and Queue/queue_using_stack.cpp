#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> s1, s2;

    void Push(int k)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(k);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int Top()
    {
        if (s1.empty())
        {
            cout << "Stack is Empty";
            exit(0);
        }
        return s1.top();
    }
    int Pop()
    {
        if (s1.empty())
        {
            cout << "Stack is already Empty";
            exit(0);
        }
        int num = s1.top();
        s1.pop();
        return num;
    }
    int size()
    {
        return s1.size();
    }
};

int main()
{
    Queue q;
    q.Push(3);
    q.Push(4);
    cout << "The element poped is " << q.Pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.size() << endl;
}
