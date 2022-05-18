#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int firstIndex(int a[], int n, int k)
{
    if (n == 0)
    {
        return -1;
    }

    if (a[0] == k)
    {
        return 0;
    }

    int ans = firstIndex(a + 1, n - 1, k);

    if (ans == -1)
    {
        return ans;
    }
    else
    {
        return 1+ans;
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
    int *a = new int[n];
    takeInputArray(a, n);
    int k;
    cin >> k;

    cout << firstIndex(a, n, k);
    return 0;
}