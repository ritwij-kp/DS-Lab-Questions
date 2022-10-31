#include <iostream>
#include <cstring>
#include<fstream>
#include <cmath>
#include <stack>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter elements of array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int start=arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i-1]=arr[i];
    }
    arr[n-1]=start;
    cout<<"Cicrcularly Permuted Array is:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}


