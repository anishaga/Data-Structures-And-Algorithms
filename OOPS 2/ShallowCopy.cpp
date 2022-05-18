#include <bits/stdc++.h>
using namespace std;

class Student
{
    private:
    int age;
    char *name;

    public:
    Student (int age, char *name)
    {
        this->age = age;
        this->name = name; //Shallow Copy
    }

    void display()
    {
        cout<<name<<" "<<age<<endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    char a[]="abcd";
    Student s1 (10,a);
    s1.display();

    a[3]= 'e';
    Student s2(20,a);
    s2.display();

    s1.display();

    return 0;
}
