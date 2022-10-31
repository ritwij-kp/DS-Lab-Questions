#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void swapString(string **stra,string **strb)
{
    string *temp;
    temp=*stra;
    *stra=*strb;
    *strb=temp;
}
int main()
{
    string *str1= new string;
    string *str2= new string;
    string **stra=&str1;
    string **strb=&str2;
    cout<<"Enter first string:"<<endl;
    getline(cin,*str1);
    cout<<"Enter second string:"<<endl;
    getline(cin,*str2);
    swapString(&str1,&str2);
    cout<<"The first string is now:"<<endl<<*str1<<endl;
    cout<<"The second string is now:"<<endl<<*str2<<endl;
}