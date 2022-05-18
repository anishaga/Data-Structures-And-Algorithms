#include <iostream>
#include <climits>
using namespace std;

int minimumCountDP(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        int j = 1;
        int x = INT_MAX;
        while (j * j <= i)
        {
            x = min(x, ans[i - (j * j)]);
            j++;
        }
        ans[i] = 1 + x;
    }
    return ans[n];
}

int minimumCountMemoization(int n, int *ans)
{
    if (n <= 0)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int i = 1;
    int x = INT_MAX;
    while (i * i <= n)
    {
        x = min(x, minimumCountMemoization(n - (i * i), ans));
        i++;
    }
    ans[n] = 1 + x;
    return ans[n];
}

int minimumCountMemoization(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return minimumCountMemoization(n, ans);
}

int minimumCount(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int x = INT_MAX;
    int i = 1;
    while (i * i <= n)
    {
        x = min(x, minimumCount(n - (i * i)));
        i++;
    }
    return 1 + x;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    cout << minimumCountDP(n) << endl;

    return 0;
}