#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n==0)
        return;
    if (n==1)
    {
      cout<<source<<" "<<destination<<endl;
      return;
    }
    towerOfHanoi(n-1,source,destination,auxiliary);
    towerOfHanoi(1,source,auxiliary,destination);
    towerOfHanoi(n-1,auxiliary,source,destination);
}
int main()
{
  towerOfHanoi(12,'a','b','c');
}


