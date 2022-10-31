#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    string expression;
    stack<char> s;
    cin>>expression;
    for (int i = 0; expression[i]!='\0'; i++)
    {
        if (expression[i]>='0' && expression[i]<='9')
        {
            s.push(expression[i]);
        }
        else
        {
            if (expression[i]=='+')
            {
                int num2=s.top()-'0';
                s.pop();
                int num1=s.top()-'0';
                s.pop();
                s.push(char('0'+(num1+num2)));
            }
            else if (expression[i]=='-')
            {
                int num2=s.top()-'0';
                s.pop();
                int num1=s.top()-'0';
                s.pop();
                s.push(char('0'+(num1-num2)));
            }
            else if (expression[i]=='*')
            {
                int num2=s.top()-'0';
                s.pop();
                int num1=s.top()-'0';
                s.pop();
                s.push(char('0'+(num1*num2)));
            }
            else if (expression[i]=='/')
            {
                int num2=s.top()-'0';
                s.pop();
                int num1=s.top()-'0';
                s.pop();
                s.push(char('0'+(num1/num2)));
            }
        }
    }
    cout<<s.top()-'0';
}


