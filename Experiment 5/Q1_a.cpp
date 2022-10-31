#include <iostream>
#include <cstring>
#include<fstream>
#include <cmath>
#include <stack>
using namespace std;
class Stack
{
private:
    int *arr;
    int size;
    int max;
public:
    Stack(int n){
        arr=new int[n];
        size=0;
        max=n;
    }
    bool isEmpty(){
        return size==0;
    }
    void Push(int n){
        if (size==max)
        {
            cout<<"Stack is full!"<<endl;
            return;
        }
        
        if (size==0)
        {
            arr[0]=n;
            size++;
            return;
        }
        for (int i = size-1; i>=0; i--)
        {
            arr[i+1]=arr[i];
        }
        arr[0]=n;
        size++;
        return;
    }
    int Pop()
    {
        int temp=arr[0];
        for (int i = 1; i <= size-1; i++)
        {
            arr[i-1]=arr[i];
        }
        size--;
        return temp;
    }
    bool isFull()
    {
        return size==max;
    }
};
int main(){
    int n;
    cout<<"Enter size of stack:"<<endl;
    cin>>n;
    Stack s1(n);
    int choice=1;
    while (choice!=0)
    {
        cout<<"Enter choice:\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n0. Exit\n";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int num;
            cout<<"Enter number to be pushed:"<<endl;
            cin>>num;
            s1.Push(num);
            break;
        case 2:
            cout<<"Element popped is "<<s1.Pop()<<endl;
            break;
        case 3:
            if (s1.isEmpty())
            {
                cout<<"The stack is empty!"<<endl;
            }
            else
            {
                cout<<"The stack is not empty."<<endl;
            }
            break;
        case 4:
            if (s1.isFull())
            {
                cout<<"The stack is full!"<<endl;
            }
            else
            {
                cout<<"The stack is not full."<<endl;
            }   
        default:
            break;
        }
    }
}


