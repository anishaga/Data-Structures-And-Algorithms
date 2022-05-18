#include <bits/stdc++.h>
using namespace std;

int sumDigits(int n)
{
    if (n==0)
    {
        return 0;
    }

    int temp = sumDigits(n/10);
    int dump = temp + n%10;
    return dump;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin>>n;

    cout<<sumDigits(n);
    return 0;
}
