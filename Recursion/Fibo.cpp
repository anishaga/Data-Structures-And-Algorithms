#include <bits/stdc++.h>
using namespace std;

int fibo (int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }

    int f1 = fibo(n-1);
    int f2 = fibo(n-2);
    return f1+f2; 
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin>>n;
    cout<<fibo(n);

    return 0;
}
