#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

bool ifSorted(int a[], int n)
{
    if (n <= 1)
    {
        return 1;
    }

    if (a[n-2] > a[n-1])
    {
        return 0;
    }

    return ifSorted(a,n-1);
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

    cout << ifSorted(a, n) << endl;

    return 0;
}