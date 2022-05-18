#include <iostream>
using namespace std;

class Vehicle
{

public:
    Vehicle()
    {
        cout << "Vehicle's Constructor" << endl;
    }

    ~Vehicle()
    {
        cout << "Vehicle's Destructor" << endl;
    }

    void print()
    {
        cout << "Vehicle" << endl;
    }
};

class Car : public Vehicle
{
public:
    Car()
    {
        cout << "Car's Constructor" << endl;
    }

    ~Car()
    {
        cout << "Car's Destructor" << endl;
    }

    void print()
    {
        cout << "Car " << endl;
    }
};

class Truck : public Vehicle
{
public:
    Truck()
    {
        cout << "Truck Constructor" << endl;
    }

    ~Truck()
    {
        cout << "Truck Destructor" << endl;
    }
};

class Bus : public Car, public Truck
{
public:
    Bus()
    {
        cout << "Bus Constructor" << endl;
    }

    ~Bus()
    {
        cout << "Bus Destructor" << endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Bus b;
    // b.print(); //Ambiguous Statement
    b.Truck::print();
    b.Car::print();


    return 0;
}
