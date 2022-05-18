#include <bits/stdc++.h>
using namespace std;

void increment1(int **p)
{
    *p=*p+1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

int i=10;
int *p = &i;
int **p2 = &p;
cout<<i<<" "<<p<<" "<<p2<<endl;
increment1(p2);
cout<<i<<" "<<p<<" "<<p2<<endl;

    return 0;
}


