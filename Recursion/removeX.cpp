#include <bits/stdc++.h>
using namespace std;

int size (int a[])
{
    int count = 0;
    for (int i=0; a[i]!='\0'; i++)
    {
        count++;
    }
    return count;
}

void removeX(char a[], int n, char string[], int index)
{
    if (n==0)
    {
        return;
    }

    if (a[0]!='x')
    {
        string[index]=a[0];
        removeX(a+1,n-1,string,index+1);
    }
    else
    {
        removeX(a+1,n-1,string,index);
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
    int n = size(a);
    char string[100];
    int index=0;
    removeX(a,n,string,index);
    cout<<string;

    return 0;
}
