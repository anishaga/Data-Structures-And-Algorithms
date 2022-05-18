#include <iostream>
using namespace std;

class Vehicle
{
private:
    int maxSpeed; // Not Accessible Outside This Class

protected:
    int numTyres; // Only Accessible Outside This Class And It's Child Class

public:
    string color; // Accessible To Everyone

    Vehicle()
    {
        cout << "Vehicle's Constructor" << endl;
    }

    Vehicle(int a)
    {
        cout << "Parametrized Constructor" << endl;
    }

    ~Vehicle()
    {
        cout << "Vehicle's Destructor" << endl;
    }
};

class Car : public Vehicle
{
public:
    int numGears;

    Car() : Vehicle(5)
    {
        cout << "Car's Constructor" << endl;
    }

    ~Car()
    {
        cout << "Car's Destructor" << endl;
    }

    void print()
    {
        cout << numTyres << endl;
        cout << color << endl;
        cout << numGears << endl;
        // cout << maxSpeed << endl; //Not Accessible
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Vehicle v;
    v.color = "Blue";
    // v.maxSpeed = 100; // Not Allowed
    // v.numTyres = 4; // Not Allowed

    Car c;
    c.color = "Black";
    // c.numTyres = 4; // Not Allowed
    c.numGears = 5;

    return 0;
}
