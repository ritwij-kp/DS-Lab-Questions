#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

string strndel(string* str,int length)
{
    string newstr="";
    int i;
    for (i = length; (*str)[i]!='\0'; i++)
    {
        newstr+=(*str)[i];
    }
    newstr[i-length]='\0';
    return newstr;
}
int main()
{
    string *str =new string;
    int length;
    cout<<"Enter a string"<<endl;
    getline(cin,(*str));
    cout<<"Enter length"<<endl;
    cin>>length;
    cout<<strndel(str,length);
}