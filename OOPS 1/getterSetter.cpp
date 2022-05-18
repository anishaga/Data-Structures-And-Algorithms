#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int roll;

private:
    int age;

public:
    void display()
    {
        cout << age << " " << roll << endl;
    }

    int getAge()
    {
        return age;
    }

    void setAge(int a)
    {
        age = a;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    Student s1;
    Student *s2 = new Student;

    s1.setAge(11);
    s2->setAge(69);

    s1.roll = 1;
    s2->roll = 2;

    s1.display();
    cout << s2->getAge() << " " << s2->roll;

    return 0;
}
