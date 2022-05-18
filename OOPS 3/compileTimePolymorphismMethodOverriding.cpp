#include <iostream>
using namespace std;

class Vehicle
{
public:
    void print()
    {
        cout << "Vehicle " << endl;
    }
};

class Car : public Vehicle
{
public:
    void print()
    {
        cout << "Car " << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    // Static Allocation

    Vehicle v;
    Car c;

    v.print();
    c.print();

    // Dynamic Allocation

    Vehicle *v1 = new Vehicle;
    Vehicle *v2;

    v2 = &c;

    v1->print();
    v2->print();

    return 0;
}
