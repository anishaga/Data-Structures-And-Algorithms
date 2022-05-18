#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int waysToChange(int a[], int n, int v)
{
    if (v == 0)
    {
        return 1;
    }
    if (v < 0)
    {
        return 0;
    }
    if (n <= 0 && v >= 1)
    {
        return 0;
    }

    return waysToChange(a, n - 1, v) + waysToChange(a, n, v - a[n - 1]);
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

    int v;
    cin >> v;

    cout << waysToChange(a, n, v) << endl;

    return 0;
}