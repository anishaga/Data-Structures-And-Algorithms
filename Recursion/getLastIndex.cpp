#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int getIndex (int a[], int n, int x)
{
    if (n<0)
    {
        return -1;
    }
    if (x==a[n])
    {
        return n;
    }
    return getIndex (a,n-1,x);
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
    cout<<getIndex(a,n-1,x);
    return 0;
}
