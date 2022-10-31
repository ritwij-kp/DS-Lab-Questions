#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of array:" << endl;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    int *arr3 = new int[2 * n];
    cout << "Enter elements of first array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter elements of second array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    int pos1 = 0, pos2 = 0, i;
    for (i = 0; i < (2 * n); i++)
    {
        if (pos1==n && pos2==n)
        {
            break;
        }
        
        if (pos1 == n)
        {
            arr3[i]=arr2[pos2];
            pos2++;
            continue;
        }
        if (pos2==n)
        {
            arr3[i]=arr1[pos1];
            pos1++;
            continue;
        }
        
        if ((arr1[pos1] <= arr2[pos2]))
        {
            arr3[i] = arr1[pos1];
            pos1++;
        }
        else
        {
            arr3[i] = arr2[pos2];
            pos2++;
        }
    }
    for (int k = 0; k < (2*n); k++)
    {
        cout<<arr3[k]<<" ";
    }
    
}