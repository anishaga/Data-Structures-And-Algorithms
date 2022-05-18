#include <bits/stdc++.h>
using namespace std;

int stair (int n)
{
    if (n < 0)
    {
        return 0;
    }

    if (n == 0)
    {
        return 1;
    }

    int t1 = stair(n - 1);
    int t2 = stair(n - 2);
    int t3 = stair(n - 3);

    return t1 + t2 + t3;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << stair(n);

    return 0;
}
