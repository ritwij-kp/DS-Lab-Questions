#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
string strdel(string str, char c){
    int j;
    for (int i = 0; str[i]!='\0'; i++)
    {
        if (str[i]==c)
        {
            for (j = i; str[j]!='\0'; j++)
            {
                str[j]=str[j+1];
            }
            str[j]='\0';
            return str;
        }
    }
    return str;
    
}
int main()
{
    string str;
    char c;
    cin>>str;
    cin>>c;
    cout<<strdel(str,c);
}