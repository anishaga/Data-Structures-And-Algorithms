#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int binarySearch(int *a, int si, int end, int x)
{
    if (si > end)
    {
        return -1;
    }

    int temp = (end - si + 1) / 2;
    temp = temp + si;
    if (a[temp] == x)
    {
        return temp;
    }
    else if (a[temp] > x)
    {
        return binarySearch(a, si, temp - 1, x);
    }
    else
    {
        return binarySearch(a, temp + 1, end, x);
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
    int x;
    cin >> x;

    cout << binarySearch(a, 0, n - 1, x) << endl;
    
    return 0;
}
