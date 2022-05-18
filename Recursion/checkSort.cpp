#include <bits/stdc++.h>
using namespace std;

void inputArray (int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
    }
}

// bool checkSort(int a[], int n)
// {
//     if (n==0)
//     {
//         return 1;
//     }
//     if (a[n] < a[n-1])
//     {
//         return 0;
//     }
//     return checkSort(a, n-1);
// }

bool checkSort(int a[], int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    if (a[0]>a[1])
    {
        return 0;
    }

    return checkSort(a+1,n-1);
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
    //cout<< checkSort(a,n-1);
    cout<< checkSort(a,n);

    return 0;
}
