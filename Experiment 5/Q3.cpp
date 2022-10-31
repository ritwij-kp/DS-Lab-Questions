#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

class stack{
    private:
    int* arr=new int[5];
    int index1=0;
    int size1=0;
    int size2=0;
    int index2=4;
    public:
    void pushStart(int n)
    {
        if (index1>index2)
        {
            cout<<"Overflow!";
            return;
        }
        
        arr[index1]=n;
        index1++;
        size1++;
    }
    void pushEnd(int n)
    {
        if (index2<index1)
        {
            cout<<"Overflow!";
            return;
        }
        
        arr[index2]=n;
        index2--;
        size2++;
    }
    int topStart()
    {
        if (size1==0)
        {
            cout<<"Stack empty!";
            return 0;
        }
        return arr[index1-1];
    }
    int topEnd()
    {
        if (size2==0)
        {
            cout<<"Stack empty!";
            return 0;
        }
        
        return arr[index2+1];
    }
    int popStart()
    {
        if (size1==0)
        {
            cout<<"Stack empty!";
            return 0;
        }
        int top=topStart();
        index1--;
        size1--;
        return top;
    }
    int popEnd()
    {
        if (size2==0)
        {
            cout<<"Stack empty!";
            return 0;
        }
        int top=topEnd();
        index2++;
        size2--;
        return top;
    }

};

int main()
{
    stack s;
    s.pushStart(1);
    s.pushStart(2);
    s.pushStart(3);
    s.pushEnd(5);
    s.pushEnd(4);
    cout<<s.topStart()<<endl<<s.topEnd()<<endl;
    cout<<s.popStart()<<endl;
    cout<<s.popStart()<<endl;
    cout<<s.popStart()<<endl;
    cout<<s.popStart()<<endl;
    cout<<s.popEnd()<<endl;
    cout<<s.popEnd()<<endl;
    cout<<s.popEnd()<<endl;
    
}


