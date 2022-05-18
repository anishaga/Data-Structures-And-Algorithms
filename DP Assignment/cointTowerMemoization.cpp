#include <iostream>
using namespace std;

int coinTower(int *dp, int n, int x, int y)
{
    if (n == 1 || n == x || n == y)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans;

    if (n > x && n > y)
    {
        ans = !coinTower(dp, n - 1, x, y) || !coinTower(dp, n - x, x, y) || !coinTower(dp, n - y, x, y);
    }
    else if (n > x && n < y)
    {
        ans = !coinTower(dp, n - 1, x, y) || !coinTower(dp, n - x, x, y);
    }
    else if (n < x && n > y)
    {
        ans = !coinTower(dp, n - 1, x, y) || !coinTower(dp, n - y, x, y);
    }
    else
    {
        ans = !coinTower(dp, n - 1, x, y);
    }

    dp[n] = ans;
    return dp[n];
}

bool coinTower(int n, int x, int y)
{
    int *dp = new int[n + 1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i] = -1;
    }

    return coinTower(dp, n, x, y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n, x, y;
    cin >> n >> x >> y;

    bool ans = coinTower(n, x, y);
    if (ans)
    {
        cout << "Beerus";
    }
    else
    {
        cout << "Whis";
    }
    return 0;
}