#include <iostream>
#include <cstring>
#include<fstream>
#include <cmath>
#include <stack>
using namespace std;
int LS(int* arr, int num, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==num)
        {
            return i;
        }
        
    }
    return -1;
}
int BS(int* arr, int si, int ei,int num)
{
    if (si>ei)
    {
        return -1;
    }
    int mid=(si+ei)/2;
    if (arr[mid]==num)
    {
        return mid;
    }
    else if (arr[mid]>num)
    {
        return BS(arr,si,mid-1,num);
    }
    else if (arr[mid]<num)
    {
        return BS(arr,mid+1,ei,num);
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    int *arr= new int[n];
    cout<<"Enter the elements of the array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int choice,num;
    cout<<"Enter number to be searched:"<<endl;
    cin>>num;
    cout<<"Enter choice:"<<endl;
    cout<<"1. Linear Search\n2. Binary Search"<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<LS(arr,num,n);
        break;
    case 2:
        cout<<BS(arr,0,(n-1),num);
        break;
    default:
        break;
    }
}
