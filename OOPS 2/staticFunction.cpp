#include <bits/stdc++.h>
using namespace std;

class Student
{
    static int totalStudents;

public:
    int roll;
    int age;

    static int getTotalStudents()
    {
        return totalStudents;
    }

    Student()
    {
        totalStudents++;
    }
};

int Student::totalStudents = 0;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Student s1, s2, s3, s4, s5;

    cout << Student::getTotalStudents();

    return 0;
}
