#include <bits/stdc++.h>
using namespace std;

void replaceChar(char a[], char c1, char c2)
{
    if (a[0]=='\0')
    {
        return;
    }
    if (a[0]==c1)
    {
        a[0]=c2;
    }
    replaceChar(a+1,c1,c2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    char a[100];
    char c1,c2;
    cin>>a;
    cin>>c1>>c2;

    replaceChar(a,c1,c2);

    cout<<a;
    return 0;
}
