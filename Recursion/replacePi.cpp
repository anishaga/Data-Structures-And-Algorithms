#include <bits/stdc++.h>
using namespace std;

int size(char a[])
{
    int count = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void replacePi(char a[], int n, char string[], int index)
{
    if (n==0)
    {
        return;
    }
    if (a[0] == 'p' && a[1] == 'i')
    {
        string[index]='3';
        index++;
        string[index]='.';
        index++;
        string[index]='1';
        index++;
        string[index]='4';
        a++;
        n--;
    }
    else
    {
        string[index]=a[0];
    }
    replacePi(a+1,n-1,string,index+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    char a[100];
    cin >> a;
    int n = size(a);
    int index=0;
    char string[100];
    replacePi(a, n, string, index);
    cout<<string;
    return 0;
}
