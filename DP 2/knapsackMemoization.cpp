#include <iostream>
using namespace std;

void takeInputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int knapsackMemoization(int *weight, int *value, int **ans, int n, int w)
{
    if (w == 0 || n == 0)
    {
        return 0;
    }

    if (ans[n][w] != -1)
    {
        return ans[n][w];
    }

    if (w - weight[n - 1] >= 0)
    {
        int x = knapsackMemoization(weight, value,ans, n - 1, w - weight[n - 1]) + value[n - 1];
        int y = knapsackMemoization(weight, value,ans, n - 1, w);
        ans[n][w] = max(x, y);
        return ans[n][w] ;
    }
    else
    {
        ans[n][w] = knapsackMemoization(weight, value,ans, n - 1, w);
        return ans[n][w];
    }
}

int knapsackMemoization(int *weight, int *value, int n, int w)
{
    int **ans = new int *[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = new int[w + 1];
        for (int j = 0; j < w + 1; j++)
        {
            ans[i][j] = -1;
        }
    }

    return knapsackMemoization(weight, value, ans, n, w);
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

    cout << knapsackMemoization(weight, value, n, w);

    return 0;
}