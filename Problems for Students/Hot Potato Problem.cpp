#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include <algorithm>
void lastSurvivor(queue<string>* line, int n)
{
    while (line->size()!=1)
    {
        for (int i = 0; i < n; i++)
        {
            line->push(line->front());
            line->pop();
        }
        cout<<"Eliminated: "<<line->front()<<endl;
        line->pop();
    }
}
int main()
{
    queue<string>* line=new queue<string>;
    line->push("Bill");
    line->push("David");
    line->push("Susan");
    line->push("Jane");
    line->push("Kent");
    line->push("Brad");
    int n;
    cout<<"Enter number of passes:"<<endl;
    cin>>n;
    lastSurvivor(line,n);
    cout<<"The last survivor is: "<<line->front();
}