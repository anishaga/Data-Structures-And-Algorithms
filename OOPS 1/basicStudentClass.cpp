#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int age;
    int roll;
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    //Static Allocation
    Student s1, s2;
    cin >> s1.age >> s1.roll;
    cout << s1.age << " " << s1.roll << endl;

    //Dynamic Allocation
    Student *s3 = new Student;
    Student *s4 = new Student;
    cin >> (*s3).age >> (*s3).roll;
    cout << (*s3).age << " " << (*s3).roll << endl;

    cin >> s4->age >> s4->roll;
    cout << s4->age << " " << s4->roll << endl;

    return 0;
}
