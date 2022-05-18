#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
}

int sumOfArray (int a[], int n)
{   
    if (n==0)
    {
        return a[n];
    }
    int temp = sumOfArray(a,n-1) + a[n]; 
    return temp;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int a[100];
    int n;
    cin>>n;

    inputArray(a,n);
    cout<<sumOfArray(a,n-1);

    return 0;
}
