#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int getIndex(int a[], int n, int x)
{
    if (n == 0)
    {
        return -1;
    }
    if (a[0] == x)
    {
        return 0;
    }
    
    int temp = getIndex(a+1,n-1,x);
    if (temp == -1)
    {
        return temp;
    }
    else
    {
        return temp+1;
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
    cout << getIndex(a, n, x);

    return 0;
}
