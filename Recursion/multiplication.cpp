#include <bits/stdc++.h>
using namespace std;

int mult(int m, int n)
{
    if (n==0)
    {
        return 0;
    }
   int temp = mult(m, n-1) + m;
   return temp;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n,m;
    cin>>m>>n;
    cout<<mult(m,n);
    return 0;
}
