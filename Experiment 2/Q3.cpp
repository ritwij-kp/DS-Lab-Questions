#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include <algorithm>
#include <unordered_map>
struct employee
{
    string employee_name;
    int employee_no;
    float employee_salary;
};

void addemployee(employee *s, int count)
{
    cout << "Enter employee name:" << endl;
    cin >> s[count].employee_name;
    cout << "Enter employee roll number:" << endl;
    cin >> s[count].employee_no;
    cout << "Enter employee salary:" << endl;
    cin >> s[count].employee_salary;
}

void displayemployee(employee *s, int count)
{
    for (int i = 0; i < count; i++)
    {

        cout << s[i].employee_name << endl
             << s[i].employee_no << endl
             << s[i].employee_salary << endl;
    }
    return;
}
int main()
{
    int n;
    cout << "Enter number of employees:" << endl;
    cin >> n;
    employee *s = new employee[n];
    int count = 0, choice, rno;
    while (true)
    {
        cout << "Enter choice:\n1. Enter record\n2. Display record\n0. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            if (count == n)
            {
                cout << "No more entries permissible\n";
                break;
            }

            addemployee(s,count);
            count++;
            break;

        case 2:
            displayemployee(s, count);

        default:
            break;
        }
    }
}