#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

bool checkNumber(int a[], int n,int k)
{
    if (n==0)
    {
        return 0;
    }

    if (a[n-1] == k)
    {
        return 1;
    }

    return checkNumber(a,n-1,k);

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

    cout << checkNumber(a,n,k);
    return 0;
}