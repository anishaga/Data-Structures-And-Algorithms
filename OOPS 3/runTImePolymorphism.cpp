#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void print()
    {
        cout << "Vehicle" << endl;
    }
};

class Car : public Vehicle
{
public:
    void print()
    {
        cout << "Car" << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Car c;
    Vehicle *v1 = new Vehicle;
    Vehicle *v2;
    v1 = &c;

    v1->print();
    v2->print();

    return 0;
}
