#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int numberOfBalancedBtDP(int h)
{
    int *ans = new int[h + 1];
    ans[0] = 1;
    ans[1] = 1;
    int mod = (int)(pow(10, 9)) + 7;

    for (int i = 2; i < h + 1; i++)
    {
        int x = ans[i - 1];
        int y = ans[i - 2];

        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)((2 * (long)(x)*y) % mod);

        ans[i] = (temp1 + temp2) % mod;
    }
    return ans[h];
}

int numberOfBalancedBTMemoization(int h, int *ans)
{
    if (h <= 1)
    {
        return 1;
    }

    if (ans[h] != -1)
    {
        return ans[h];
    }

    int mod = (int)(pow(10, 9)) + 7;
    int x = numberOfBalancedBTMemoization(h - 1, ans);
    int y = numberOfBalancedBTMemoization(h - 2, ans);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);

    ans[h] = (temp1 + temp2) % mod;

    return ans[h];
}

int numberOfBalancedBTMemoization(int h)
{
    int *ans = new int[h + 1];
    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i < h + 1; i++)
    {
        ans[i] = -1;
    }

    return numberOfBalancedBTMemoization(h, ans);
}

int numberOfBalancedBT(int h)
{
    if (h <= 1)
    {
        return 1;
    }

    int mod = (int)(pow(10, 9)) + 7;
    int x = numberOfBalancedBT(h - 1);
    int y = numberOfBalancedBT(h - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);

    int ans = (temp1 + temp2) % mod;
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int h;
    cin >> h;

    cout << numberOfBalancedBtDP(h) << endl;

    return 0;
}