#include <iostream>
using namespace std;

int fiboDP(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n];
}

int fiboMemoization(int n, int *ans)
{
    if (n <= 0)
    {
        return 0;
    }

    if (n <= 2)
    {
        return 1;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    ans[n] = fiboMemoization(n - 1, ans) + fiboMemoization(n - 2, ans);
    return ans[n];
}

int fiboMemoization(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    return fiboMemoization(n, ans);
}

int fibo(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    if (n <= 2)
    {
        return 1;
    }

    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    cout << fiboDP(n) << endl;

    return 0;
}