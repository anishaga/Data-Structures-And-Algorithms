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
};

class Car : public Vehicle
{
public:
    int numGears;

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
    c.numTyres = 4; //Not Allowed
    c.numGears = 5;

    return 0;
}
