#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    int age;
    char *name;

    void display() const
    {
        cout << name << " " << age << endl;
    }

    Student(int age, char *name)
    {
        this->age = age;
        this->name = new char[strlen(name) + 1]; 
        strcpy((this->name), name);
    }

    Student(Student const &s)
    {
        this->age = s.age;
        this->name = new char[strlen(s.name) + 1]; 
        strcpy((this->name), s.name);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    char a[]="mexico";
    Student s1(10,a);
    s1.display();
    Student s2(s1);
    s2.name[0]='s';
    s2.display();
    s1.display();

    return 0;
}
