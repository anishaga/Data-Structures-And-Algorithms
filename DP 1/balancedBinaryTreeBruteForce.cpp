#include <iostream>
#include <cmath>
using namespace std;

int numberOfBT(int h)
{
    if (h <= 1)
    {
        return 1;
    }
    int mod = (int) (pow(10, 9)) + 7;
    int x = numberOfBT(h - 1);
    int y = numberOfBT(h - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);

    return (temp1 + temp2) % mod;

    // return x*x + x*y + y*x;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int h;
    cin >> h;

    cout << numberOfBT(h);

    return 0;
}