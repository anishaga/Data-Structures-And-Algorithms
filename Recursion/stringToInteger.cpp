#include <bits/stdc++.h>
using namespace std;

int size(char a[])
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
void printArray(int k[], int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<k[i];
    }
}

void stringToInteger(char a[], int n, int k[])
{
    if (n == 0)
    {
        return;
    }
    k[0] = a[0] - 48;
    stringToInteger(a+1,n-1,k+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    char a[100];
    cin >> a;
    int n = size(a);
    int k[100];

    stringToInteger(a, n, k);

    printArray(k,n);
    return 0;
}
