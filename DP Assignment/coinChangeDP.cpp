#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int waysToChange(int a[], int n, int v)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[v + 1];
    }

    // Filling The First Row
    for (int j = 1; j < v + 1; j++)
    {
        dp[0][j] = 0;
    }

    // Filling The First Column
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    // Filling Remaining Cells

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < v + 1; j++)
        {
            if (a[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - a[i - 1]];
            }
        }
    }

    return dp[n][v];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int *a = new int[n];
    takeInputArray(a, n);

    int v;
    cin >> v;

    cout << waysToChange(a, n, v) << endl;

    return 0;
}