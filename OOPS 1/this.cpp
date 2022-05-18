#include <bits/stdc++.h>
using namespace std;

class Student
{

private:
    int age;

public:
    void display()
    {
        cout << age << endl;
    }
    Student(int age) 
    {
        cout<<"Address In this: "<<this<<endl;
        this -> age = age;
    }

};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Student s1(10);
    cout << "Address Of S1: "<<&s1 <<endl;
    s1.display();

    Student *s2 = new Student (20);
    cout<< "Address Of S2: "<<s2 << endl;
    s2-> display();

    return 0;
}
