#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int arr[11]={};
    queue<int> q;
    while (true)
    {
        int data;
        cin>>data;
        if (data==-1)
        {
            break;
        }
        q.push(data);
    }
    while (!q.empty())
    {
        if (q.front()==5)
        {
            q.pop();
            arr[5]++;
        }
        else if (q.front()==10)
        {
            if (arr[5]==0)
            {
                cout<<"Change unavailable!";
                return 0;
            }
            arr[5]--;
            arr[10]++;
            q.pop();
        }
        else if (q.front()==20)
        {
            if (arr[5]==0 || arr[10]==0)
            {
                if (arr[5]<3)
                {
                    cout<<"Change unavailable!";
                    return 0;
                }
                arr[5]-=3;
                q.pop();
            }
            else
            {
                arr[10]--;
                arr[5]--;
                q.pop();
            }
        }
    }
    cout<<"Change was available all the time.";
}
