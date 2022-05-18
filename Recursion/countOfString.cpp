#include <bits/stdc++.h>
using namespace std;

int size (char a[])
{
    if (a[0]=='\0')
    {
        return 0;
    }
    else
    {
        int temp= size(a+1) +1;
        return temp;
    }
    
}   
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    char a[100];
    cin>>a;
    cout<<size(a);
    return 0;
}
