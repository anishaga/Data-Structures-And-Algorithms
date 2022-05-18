#include <iostream>
#include <cmath>
using namespace std;

int allPossibleWays(int a, int b, int curr)
{
    int ans = pow(curr, b);
    if (ans == a)
    {
        return 1;
    }
    if (ans > a)
    {
        return 0;
    }

    return allPossibleWays(a - ans, b, curr + 1) + allPossibleWays(a, b, curr + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int a;
    cin >> a;

    int b;
    cin >> b;

    cout << allPossibleWays(a, b, 1);
    return 0;
}