#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int binarySearch(int a[], int index, int n, int x)
{
    if (index > n)
    {
        return -1;
    }

    int mid = (index + n) / 2;
    // cout << "Index: " << index << endl;
    // cout << "Mid: " << mid << endl;
    // cout << "n: " << n << endl;

    if (a[mid] == x)
    {
        return mid;
    }
    else if (a[mid] < x)
    {
        return binarySearch(a, mid + 1, n, x);
    }
    else
    {
        return binarySearch(a, index, mid - 1, x);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int a[100];
    int n;

    cin >> n;
    inputArray(a, n);

    int x;
    cin >> x;

    int index = 0;

    cout << binarySearch(a, index, n - 1, x);

    return 0;
}
