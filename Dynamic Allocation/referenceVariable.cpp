#include <bits/stdc++.h>
using namespace std;

void increment(int& i)
{
    i++;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

int i=10;
increment(i);
cout<<i;

    return 0;
}
