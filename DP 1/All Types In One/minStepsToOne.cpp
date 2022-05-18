#include <iostream>
#include <climits>
using namespace std;

int minStepsToOneDP(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 0;

    for (int i = 2; i < n + 1; i++)
    {
        int x = ans[i - 1];

        if (i % 2 == 0)
        {
            x = min(x, ans[i / 2]);
        }

        if (i % 3 == 0)
        {
            x = min(x, ans[i / 3]);
        }

        ans[i] = 1 + x;
    }
    return ans[n];
}

int minStepsToOneMemoization(int n, int *ans)
{
    if (n == 1)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int x = minStepsToOneMemoization(n - 1, ans);
    int y = INT_MAX;
    int z = INT_MAX;

    if (n % 2 == 0)
    {
        y = minStepsToOneMemoization(n / 2, ans);
    }

    if (n % 3 == 0)
    {
        z = minStepsToOneMemoization(n / 3, ans);
    }

    ans[n] = 1 + min(x, min(y, z));
    return ans[n];
}

int minStepsToOneMemoization(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 0;

    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return minStepsToOneMemoization(n, ans);
}

int minStepsToOne(int n)
{
    if (n == 1)
    {
        return 0;
    }

    int x = minStepsToOne(n - 1);
    int y = INT_MAX;
    int z = INT_MAX;

    if (n % 2 == 0)
    {
        y = minStepsToOne(n / 2);
    }

    if (n % 3 == 0)
    {
        z = minStepsToOne(n / 3);
    }

    return 1 + min(x, min(y, z));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << minStepsToOneDP(n) << endl;
    return 0;
}