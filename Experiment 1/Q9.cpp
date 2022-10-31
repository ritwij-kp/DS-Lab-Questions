#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout<<"Enter range:"<<endl;
    cin>>n;
    int *arr=new int[n];
    int *freq=new int[n+1];
    for (int i = 0; i <= n; i++)
    {
        freq[i]=0;
    }
    cout<<"Enter the elenents in the array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    cout<<"The missing numbers are:"<<endl;
    for (int i = 1; i <= n; i++)
    {
        if (freq[i]==0)
        {
            cout<<i<<" ";
        }
    }
}