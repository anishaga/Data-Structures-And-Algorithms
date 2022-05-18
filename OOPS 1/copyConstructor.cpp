#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int age, roll;

    void display()
    {
        cout << age << " " << roll << endl;
    }

    Student(int a, int r)
    {
        age = a;
        roll = r;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    Student s1(10, 1);
    s1.display();
    Student s2(s1);
    s2.display();

    Student *s3 = new Student(s1);
    s3->display();
    Student *s4 = new Student(*s3);
    s4->display();

    return 0;
}
