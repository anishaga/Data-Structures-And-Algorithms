#include <iostream>
using namespace std;

class Bus
{
public:
    void print();
};

void test();

class Truck
{
private:
    int x;

protected:
    int y;

public:
    int z;

    friend void Bus::print(); // Declaring Friend

    friend void test();
};

void Bus::print()
{
    Truck t;
    t.x = 10;
    t.y = 20;

    cout << t.x << " " << t.y << endl;
}

void test()
{
    Truck t;
    t.x = 1;
    t.y = 2;

    cout << t.x <<" " << t.y << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Bus b;
    b.print();
    test();

    return 0;
}
