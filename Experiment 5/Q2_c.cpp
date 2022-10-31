#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

bool isBalanced(string expression)
{
    stack<char> s1;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            s1.push(expression[i]);
            continue;
        }
        if (expression[i] == ')')
        {
            if (s1.empty())
            {
                return false;
            }

            if (s1.top() == '(')
            {
                s1.pop();
                continue;
            }
            else
            {
                return false;
            }
        }
        else if (expression[i] == '}')
        {
            if (s1.empty())
            {
                return false;
            }
            if (s1.top() == '{')
            {
                s1.pop();
                continue;
            }
            else
            {
                return false;
            }
        }
        else if (expression[i] == ']')
        {
            if (s1.empty())
            {
                return false;
            }
            if (s1.top() == ']')
            {
                s1.pop();
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    if (s1.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}


