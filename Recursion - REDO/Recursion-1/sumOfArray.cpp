#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int sumOfArray(int a[], int n)
{
    if (n == 1)
    {
        return a[n-1];
    }

    return a[n-1] + sumOfArray(a,n-1);
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

    cout <<sumOfArray(a,n);
    return 0;
}