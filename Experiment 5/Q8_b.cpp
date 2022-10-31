#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include <algorithm>
#include <unordered_map>
class DeQueue{
    public:
    int arr[10];
    int front;
    int rear;
    int size;

    DeQueue()
    {
        front=-1;
        rear=0;
        size=0;
    }

    void frontPush(int n)
    {
        if (front==-1)
        {
            front=0;
            rear=0;
            arr[front]=n;
            size=1;
            return;
        }
        else if (front==0)
        {
            front=9;
            arr[front]=n;
        }
        else
        {
            front--;
            arr[front]=n;
        }
        size++;
    }

    void rearPush(int n)
    {
        if (rear==0 && front==-1)
        {
            arr[rear]=n;
            size=1;
            return;
        }
        else if (rear==9)
        {
            rear=0;
            arr[rear]=n;
        }
        else
        {
            rear++;
            arr[rear]=n;
        }
        size++;
    }

    int frontPop()
    {
        if (size==0)
        {
            cout<<"Underflow!";
            return 0;
        }
        
        if (size==1)
        {
            front=-1;
            rear=0;
            return arr[front];
        }
        int n=arr[front];
        if (front==9)
        {
            front=0;
            return n;
        }
        else
        {
            front++;
            return n;
        }
    }

    int rearPop()
    {
        if (size==0)
        {
            cout<<"Underflow!";
            return 0;
        }
        if (size==1)
        {
            front=-1;
            rear=0;
            return arr[rear];
        }
        
        int n=arr[rear];
        if (rear==0)
        {
            rear=9;
            return n;
        }
        else
        {
            rear--;
            return n;
        }
    }

    bool isEmpty()
    {
        return size==0;
    }
    int showFront()
    {
        return arr[front];
    }

    int showRear()
    {
        return arr[rear];
    }
};

int main()
{
    DeQueue dq;
    dq.frontPush(1);
    dq.rearPush(2);
    cout<<dq.showFront()<<endl;
    cout<<dq.showRear()<<endl;
    dq.rearPush(3);
    cout<<dq.showFront()<<endl;
    cout<<dq.showRear()<<endl;
    cout<<dq.rearPop();
    cout<<dq.rearPop();
    cout<<dq.rearPop();


}