#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include <algorithm>
#include <unordered_map>
int main()
{
  stack<char> s;
  string expression;
  string output="";
  cin>>expression;
  for (int i = expression.size()-1; i>=0; i--)
  {
    if (expression[i]>='A' && expression[i]<='Z')
    {
      output=expression[i]+output;
    }
    else if (expression[i]==')')
    {
      s.push(')');
    }
    else if (expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/')
    {
      if (s.top()=='+' || s.top()=='-' || s.top()=='*' || s.top()=='/')
      {
        if ((expression[i]=='*'||expression[i]=='/') && (s.top()=='*' || s.top()=='/'))
        {
          output=(s.top())+output;
          s.pop();
          s.push(expression[i]);
        }
        else if ((expression[i]=='+'||expression[i]=='-') && (s.top()=='+' || s.top()=='-'))
        {
          output=(s.top())+output;
          s.pop();
          s.push(expression[i]);
        }
        else if ((expression[i]=='+'||expression[i]=='-') && (s.top()=='*' || s.top()=='/'))
        {
          output=(s.top())+output;
          s.pop();
          s.push(expression[i]);
        }
        
        else
        {
          s.push(expression[i]);
        }
      }
      else
      {
        s.push(expression[i]);
      }
    }
    else if (expression[i]=='(')
    {
      while (s.top()!=')')
      {
        output=s.top()+output;
        s.pop();
      }
      s.pop();
    }
  }
  cout<<output;
}
