#include <iostream>
#include <climits>
using namespace std;

int minCostPathDP(int **mat, int m, int n)
{
    int **dp = new int *[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
    }

    // Filling The Last Cell i.e Destination
    dp[m - 1][n - 1] = mat[m - 1][n - 1];

    // Filling The Last Row in Right -> Left Order
    for (int j = n - 2; j >= 0; j--)
    {
        dp[m - 1][j] = mat[m - 1][j] + dp[m - 1][j + 1];
    }

    // Filling The Last Column In Bottom -> Top Order
    for (int i = m - 2; i >= 0; i--)
    {
        dp[i][n - 1] = mat[i][n - 1] + dp[i + 1][n - 1];
    }

    // Filling Remaining Cells
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            dp[i][j] = mat[i][j] +  min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
        }
    }

    return dp[0][0];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int m;
    cin >> m;
    int n;
    cin >> n;

    int **mat = new int *[m];

    for (int i = 0; i < m; i++)
    {
        mat[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << minCostPathDP(mat, m, n);

    return 0;
}