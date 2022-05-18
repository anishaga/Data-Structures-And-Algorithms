#include <iostream>
#include <string>
using namespace std;

class Teacher
{
    public:
    void print()
    {
        cout << "Teacher " << endl;
    }
};

class Student
{
    public:
    void print()
    {
        cout << "Student " << endl;
    }
};

class TA : public Teacher, public Student
{
    public:
    void print()
    {
        cout <<"TA" << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    TA a;
    a.print(); // Ambigious Statement If There Is Not Print In TA
    a.Student :: print();
    a.Teacher :: print();
    
    return 0;
}

