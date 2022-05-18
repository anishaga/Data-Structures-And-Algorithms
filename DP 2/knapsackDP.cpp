#include <iostream>
using namespace std;

void takeInputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int knapsackDP(int *weight, int *value, int n, int w)
{
    int **dp = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i] = new int[w + 1];
    }

    // Filling First Row As 0
    for (int j = 0; j <= w; j++)
    {
        dp[0][j] = 0;
    }

    // Filling First Column As 0
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    // Filling Rest Of The Cells

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (weight[i - 1] <= j)
            {
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][w];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int *weight = new int[n];
    int *value = new int[n];

    takeInputArray(weight, n);
    takeInputArray(value, n);

    int w;
    cin >> w;

    cout << knapsackDP(weight, value, n, w);

    return 0;
}