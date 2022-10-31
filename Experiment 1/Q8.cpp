#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    int *arr= new int[n];
    int max=INT32_MIN;
    cout<<"Enter elements of array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        if (arr[i]>max)
        {
            max=arr[i];
        }
    }
    int *freq= new int[max+1];
    for (int i = 0; i <= max; i++)
    {
        freq[i]=0;
    }
    
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    cout<<"The non repeated elements in the array are:"<<endl;
    for (int i = 0; i <= max; i++)
    {
        if (freq[i]==1)
        {
            cout<<i<<" ";
        }
    }
}