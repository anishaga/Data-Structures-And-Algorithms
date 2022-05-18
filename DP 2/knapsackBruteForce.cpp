#include <iostream>
using namespace std;

void takeInputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int maxSteal(int *weight, int *value, int n, int w)
{
    if (w == 0 || n == 0)
    {
        return 0;
    }

    if (w - weight[n - 1] >= 0)
    {
        int x = maxSteal(weight, value, n - 1, w - weight[n - 1]) + value[n - 1];
        int y = maxSteal(weight, value, n - 1, w);
        return max(x, y);
    }
    else
    {
        return maxSteal(weight, value, n - 1, w);
    }
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

    cout << maxSteal(weight, value, n, w) << endl;

    return 0;
}