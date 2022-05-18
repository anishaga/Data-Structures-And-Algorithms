#include <iostream>
using namespace std;

int maxSquare(int **a, int r, int c)
{
    int **dp = new int *[r];
    for (int i = 0; i < r; i++)
    {
        dp[i] = new int[c];
    }

    int maxi = 0;

    // Filling First Row
    for (int j = 0; j < c; j++)
    {
        if (a[0][j] == 0)
        {
            dp[0][j] = 1;
            maxi = max(maxi, dp[0][j]);
        }
        else
        {
            dp[0][j] = 0;
        }
    }

    // Filling First Column
    for (int i = 0; i < r; i++)
    {
        if (a[i][0] == 0)
        {
            dp[i][0] = 1;
            maxi = max(maxi, dp[i][0]);
        }
        else
        {
            dp[i][0] = 0;
        }
    }

    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                maxi = max(maxi, dp[i][j]);
            }
        }
    }
    return maxi;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int r, c;
    cin >> r >> c;
    int **a = new int *[r];
    for (int i = 0; i < r; i++)
    {
        a[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            int temp;
            cin >> temp;
            a[i][j] = temp;
        }
    }
    cout << maxSquare(a, r, c);

    return 0;
}