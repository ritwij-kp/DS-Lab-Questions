#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    stack<char> s;
    string str;
    cin>>str;
    for (int i = 0; str[i]!='\0'; i++)
    {
        s.push(str[i]);
    }
    for (int i = 0; str[i]!='\0'; i++)
    {
        if (str[i]!=s.top())
        {
            cout<<"Not a palindrome";
            return 0;
        }
        s.pop();
    }
    cout<<"It is a palindrome";
    
}


