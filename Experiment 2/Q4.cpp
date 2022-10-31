#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#include <algorithm>
#include <unordered_map>
struct faculty
{
    string faculty_name;
    int faculty_id;
    int subject_id;
};

void addfaculty(faculty *s, int count)
{
    cout << "Enter faculty name:" << endl;
    cin >> s[count].faculty_name;
    cout << "Enter faculty roll number:" << endl;
    cin >> s[count].faculty_id;
    cout << "Enter faculty salary:" << endl;
    cin >> s[count].subject_id;
}

void displayfaculty(faculty *s, int count)
{
    for (int i = 0; i < count; i++)
    {

        cout << s[i].faculty_name << endl
             << s[i].faculty_id << endl
             << s[i].subject_id << endl;
    }
    return;
}
int main()
{
    int n;
    cout << "Enter number of facultys:" << endl;
    cin >> n;
    faculty *s = new faculty[n];
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

            addfaculty(s,count);
            count++;
            break;

        case 2:
            displayfaculty(s, count);

        default:
            break;
        }
    }
}