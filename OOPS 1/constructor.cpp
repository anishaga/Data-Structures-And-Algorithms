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

    //Default Constructor
    Student()
    {
        cout << "Constructor 1 Called " << endl; //Checking Whether It Gets Called
    }
 
    //Parametrized Constructor With Single Parameter
    Student(int a) 
    {
        cout << "Constructor 2 Called" << endl;
        age = a;
    }

    //Parametrized Constructor With Two Parameters
    Student(int a, int r) 
    {
        cout << "Constructor 3 Called" << endl;
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
    Student s1;
    s1.display();
    Student *s2 = new Student;
    s2->display();

    Student s3(10);
    s3.display();
    Student *s4 = new Student(12);
    s4->display();

    Student s5(10, 15);
    s5.display();
    Student *s6 = new Student(11, 20);
    s6->display();

    return 0;
}
