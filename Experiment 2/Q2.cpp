#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct student
{
    string student_name;
    int student_rollno;
    float student_marks;
};

void addStudent(student *s, int count)
{
    cout << "Enter student name:" << endl;
    cin >> s[count].student_name;
    cout << "Enter student roll number:" << endl;
    cin >> s[count].student_rollno;
    cout << "Enter student marks:" << endl;
    cin >> s[count].student_marks;
}

void displayStudent(student *s, int count)
{
    for (int i = 0; i < count; i++)
    {

        cout << s[i].student_name << endl
             << s[i].student_rollno << endl
             << s[i].student_marks << endl;
    }
    return;
}
int main()
{
    int n;
    cout << "Enter number of students:" << endl;
    cin >> n;
    student *s = new student[n];
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

            addStudent(s,count);
            count++;
            break;

        case 2:
            displayStudent(s, count);

        default:
            break;
        }
    }
}
