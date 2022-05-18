#include <iostream>
using namespace std;

int staircaseDP(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;

    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }
    return ans[n];
}

int staircaseMemoization(int n, int *ans)
{
    if (n < 0)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    return staircaseMemoization(n - 1, ans) + staircaseMemoization(n - 2, ans) + staircaseMemoization(n - 3, ans);
}
int staircaseMemoization(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;

    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return staircaseMemoization(n, ans);
}

int staircase(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }

    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << staircaseDP(n) << endl;

    return 0;
}