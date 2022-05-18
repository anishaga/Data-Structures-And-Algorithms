#include <iostream>
using namespace std;

int minSteps(int n, int *ans)
{
    if (n == 1)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int x = minSteps(n - 1,ans);
    int y = INT_MAX;
    int z = INT_MAX;

    if (n % 3 == 0)
    {
        y = minSteps(n / 3,ans);
    }
    if (n % 2 == 0)
    {
        z = minSteps(n / 2,ans);
    }

    ans[n] =  1 + min(x, min(y, z));
    return ans[n];
}

int minSteps(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 0;

    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return minSteps(n, ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << minSteps(n) << endl;

    return 0;
}