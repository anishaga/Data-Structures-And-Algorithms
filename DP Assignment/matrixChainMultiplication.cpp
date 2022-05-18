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

int matrixChain(int a[], int si, int ei)
{
    if (si == ei || si == ei - 1)
    {
        return 0;
    }

    int ans = INT_MAX;
    int k = si + 1;
    while (k < ei)
    {
        ans = min(ans, matrixChain(a, si, k) + matrixChain(a, k, ei) + (a[si] * a[k] * a[ei]));
        k++;
    }
    return ans;
}

int matrixChain(int a[], int n)
{
    return matrixChain(a, 0, n);
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