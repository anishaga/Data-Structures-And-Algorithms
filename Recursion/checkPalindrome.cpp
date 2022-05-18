#include <bits/stdc++.h>
using namespace std;

int size (char a[])
{
    int count =0;
    for (int i=0; a[i]!='\0'; i++)
    {
        count++;
    }
    return count;
}
bool checkPalindrome (char a[], int n, int i)
{

    if (i>=n)
    {
        return 1;
    }
    if(a[i]!=a[n])
    {
        return 0;
    }
   return checkPalindrome(a,n-1,i+1);
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
    int i=0;
    cout<<checkPalindrome(a,n-1,i);
    return 0;
}
