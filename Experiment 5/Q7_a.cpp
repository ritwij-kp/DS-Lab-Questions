#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

class Queue{
    private:
    int* arr= new int[5];
    int fi;
    int size;
    int capacity;
    int ni;

    public:
    Queue()
    {
        fi=-1;
        size=0;
        capacity=5;
        ni=0;
    }
    bool isEmpty()
    {
        return size==0;
    }
    void enqueue(int n)
    {
        if (fi==-1)
        {
            fi=0;
        }
        if (size==capacity)
        {
            cout<<"Queue full!";
            return;
        }
        arr[ni]=n;
        ni=(ni+1)%capacity;
        size++;
    }
    int dequeue()
    {
        if (size==0)
        {
            cout<<"Queue empty!";
            return -1;
        }
        int ans=arr[fi];
        fi=(fi+1)%capacity;
        size--;
        if (size==0)
        {
            fi=-1;
            ni=0;
        }
        return ans;
    }
    int front()
    {
        return arr[fi];
    }
};

int main()
{
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    cout<<q1.front();
    cout<<endl;
    cout<<q1.dequeue();
    cout<<endl;
    cout<<q1.front();
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    cout<<endl;
    cout<<q1.front();
    cout<<endl;
    cout<<q1.dequeue();
    cout<<endl;
    cout<<q1.front();
    q1.enqueue(70);


}


