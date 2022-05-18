#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void print() = 0;
};

class Truck : public Vehicle
{
public:
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

    // Vehicle v; // Not Allowed Since Vehicle Is Abstract Class
    // Truck t;   // Not Allowed, Truck Has Now Also Become Abstract
    Car c; // Allowed Because Car Has Implemented The Virtual Functions

    return 0;
}
