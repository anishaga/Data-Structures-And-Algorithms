#include <bits/stdc++.h>
using namespace std;

int raise (int x, int n)
{
    if (n==0)
    {
        return 1;
    }
    int temp = x* raise(x,n-1);
    return temp;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int x,n;
    cin>>x>>n;

    cout<<raise(x,n);


    return 0;
}
