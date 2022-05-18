#include <iostream>
#include <cmath>
using namespace std;

int allPossibleWays(int a, int b, int curr, int **dp)
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

    if (dp[a][curr] != -1)
    {
        return dp[a][curr];
    }

    dp[a][curr] = allPossibleWays(a - ans, b, curr + 1, dp) + allPossibleWays(a, b, curr + 1, dp);
    return dp[a][curr];
}

int allPossibleWays(int a, int b)
{
    int **dp = new int *[a + 1];
    int temp = a / 2;
    for (int i = 0; i < a + 1; i++)
    {
        dp[i] = new int[temp];
        for (int j = 0; j < temp; j++)
        {
            dp[i][j] = -1;
        }
    }

    return allPossibleWays(a, b, 1, dp);
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

    cout << allPossibleWays(a, b);
    return 0;
}