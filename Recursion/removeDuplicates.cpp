#include <bits/stdc++.h>
using namespace std;

void removeDuplicates( char a[])
{
    if (a[0]=='\0')
    {
        return;
    }
    if (a[0]==a[1])
    {
        int i;
        for (i=1; a[i]!='\0';i++)
        {
            a[i]=a[i+1];
        }
        removeDuplicates(a);
    }
    else
    {
        removeDuplicates(a+1);
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

    removeDuplicates(a);
    cout<<a;


    return 0;
}
