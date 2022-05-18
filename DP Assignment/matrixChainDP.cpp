#include <iostream>
#include <climits>
using namespace std;

void takeInputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int matrixChain(int a[], int n)
{
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[n];
    }

    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + a[i - 1] * a[k] * a[j];
                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }
    return dp[1][n - 1];

    // // Filling First Row
    // for (int j = 0; i < n + 1; j++)
    // {
    //     dp[0][j] = 0;
    // }

    // // Filling First Column
    // for (int i = 0; i < n + 1; i++)
    // {
    //     dp[i][0] = 0;
    // }

    // return matrixChain(a, dp, );
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int *a = new int[n + 1];
    takeInputArray(a, n + 1);

    cout << matrixChain(a, n + 1);

    return 0;
}