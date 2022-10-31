#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void freq(string *str)
{
    int arr1[26]={};
    int arr2[26]={};
    for (int i = 0; (*str)[i]!='\0'; i++)
    {
        if ((*str)[i]>='a' && (*str)[i]<='z')
        {
            arr1[((*str)[i])-'a']++;
        }
        else if ((*str)[i]>='A' && (*str)[i]<='Z')
        {
            arr2[((*str)[i])-'A']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr1[i]!=0)
        {
            cout<<char('a'+i)<<":"<<arr1[i]<<endl;
        }
        if (arr2[i]!=0)
        {
            cout<<char('A'+i)<<":"<<arr2[i]<<endl;
        }
    }
}
int main()
{
    string *str=new string;
    cout<<"Enter a string"<<endl;
    getline(cin,*str);
    freq(str);
}