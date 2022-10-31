#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include <algorithm>
//13 1 26 1 12 1 17 1 15 1 34 1 66 1 42 1 32 1 11
int main()
{
  stack<int> p1, p2;
  int choice = 1;
  while (choice)
  {
    int n;
    cin >> n;
    p1.push(n);
    cout << "Enter more elements? (1 for yes, 0 for no)" << endl;
    cin >> choice;
  }
  int count = 0;
  bool flag = true;
  while (flag)
  {
    flag = false;
    while (!p1.empty())
    {
      int n1 = p1.top();
      p1.pop();
      if (!p1.empty())
      {
        int n2 = p1.top();
        p1.pop();
        if (n1 < n2)
        {
          flag = true;
          p1.push(n2);
        }
        else
        {
          p2.push(n1);
          p1.push(n2);
        }
      }
      else
      {
        p2.push(n1);
      }  
    }
    while (!p2.empty())
    {
      p1.push(p2.top());
      p2.pop();
    }
    count++;
  }
  cout<<"Final stack of plants is:";
  while (!p1.empty())
  {
    cout<<p1.top()<<" ";
    p1.pop();
  }
  cout<<"\nNumber of days: "<<count-1;
}
