#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int waysToChange(int a[], int n, int v, int **dp)
{
    if (v == 0)
    {
        return 1;
    }
    if (v < 0)
    {
        return 0;
    }
    if (n <= 0 && v >= 1)
    {
        return 0;
    }

    if (dp[n][v] != -1)
    {
        return dp[n][v];
    }

    dp[n][v] = waysToChange(a, n - 1, v, dp) + waysToChange(a, n, v - a[n - 1], dp);
    return dp[n][v];
}

int waysToChange(int a[], int n, int v)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[v + 1];

        for (int j = 0; j < v + 1; j++)
        {
            dp[i][j] = -1;
        }
    }

    return waysToChange(a, n, v, dp);
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