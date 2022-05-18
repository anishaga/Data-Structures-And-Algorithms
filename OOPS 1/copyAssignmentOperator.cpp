#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int age, roll;

    void display()
    {
        cout << age << " " << roll<<endl;
    }

    Student(int a, int r)
    {
        age = a;
        roll = r;
    }
};

int
main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Student s1(10,1);
    Student s2(20,2);
    Student *s3 = new Student (30,3);
    s1.display();
    s2.display();
    s3->display();

    *s3 = s2;
    s1 = *s3;
    s2 = s1;

    cout<<"After Changes: "<<endl;
    s1.display();
    s2.display();
    s3->display();   

    return 0;
}
