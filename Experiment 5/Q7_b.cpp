#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include <algorithm>
#include <unordered_map>
class Queue{
    public:
    stack<int> s1;
    stack<int> s2;

    void enqueue(int n)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(n);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    bool isEmpty()
    {
        return s1.empty();
        
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout<<"Queue Empty!";
            return -1;
        }
        
        int n;
        n=s1.top();
        s1.pop();
        return n;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout<<"Queue Empty!";
            return -1;
        }
        return s1.top();
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.peek()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

}