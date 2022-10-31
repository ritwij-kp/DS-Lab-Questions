#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int main()
{
  stack<char> s;
  string expression;
  string output="";
  cin>>expression;
  for (int i = 0; expression[i]!='\0'; i++)
  {
    if (expression[i]>='A' && expression[i]<='Z')
    {
      output+=expression[i];
    }
    else if (expression[i]=='(')
    {
      s.push('(');
    }
    else if (expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/')
    {
      if (s.top()=='+' || s.top()=='-' || s.top()=='*' || s.top()=='/')
      {
        if ((expression[i]=='*'||expression[i]=='/') && (s.top()=='*' || s.top()=='/'))
        {
          output+=(s.top());
          s.pop();
          s.push(expression[i]);
        }
        else if ((expression[i]=='+'||expression[i]=='-') && (s.top()=='+' || s.top()=='-'))
        {
          output+=(s.top());
          s.pop();
          s.push(expression[i]);
        }
        else if ((expression[i]=='+'||expression[i]=='-') && (s.top()=='*' || s.top()=='/'))
        {
          output+=(s.top());
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
    else if (expression[i]==')')
    {
      while (s.top()!='(')
      {
        output+=s.top();
        s.pop();
      }
      s.pop();
    }
  }
  cout<<output;
}


