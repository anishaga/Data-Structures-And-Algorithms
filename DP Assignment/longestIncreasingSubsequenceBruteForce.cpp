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

int lis(int *a, int n, int prev)
{
    if (n == 0)
    {
        return 0;
    }

    if (a[0] > prev)
    {
        return max(1 + lis(a + 1, n - 1, a[0]), lis(a + 1, n - 1, prev));
    }
    else
    {
        return lis(a + 1, n - 1, prev);
    }
}

int lis(int *a, int n)
{
    return lis(a, n, INT_MIN);
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

    cout << lis(a, n);
    return 0;
}