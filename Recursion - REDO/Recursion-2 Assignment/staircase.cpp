#include <iostream>
using namespace std;

int staircase(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << staircase(n) << endl;

    return 0;
}