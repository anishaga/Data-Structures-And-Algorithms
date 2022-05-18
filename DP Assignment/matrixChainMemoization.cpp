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

int matrixChain(int a[], int **dp, int si, int ei)
{
    if (si == ei || si == ei - 1)
    {
        return 0;
    }
    if (dp[si][ei] != -1)
    {
        return dp[si][ei];
    }

    int ans = INT_MAX;
    int k = si + 1;
    while (k < ei)
    {
        ans = min(ans, matrixChain(a, dp, si, k) + matrixChain(a, dp, k, ei) + (a[si] * a[k] * a[ei]));
        k++;
    }
    dp[si][ei] = ans;
    return dp[si][ei];
}

int matrixChain(int a[], int n)
{
    int **dp = new int *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            dp[i][j] = -1;
        }
    }

    return matrixChain(a, dp, 0, n);
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

    cout << matrixChain(a, n);

    return 0;
}