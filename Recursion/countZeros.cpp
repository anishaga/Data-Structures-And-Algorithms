#include <bits/stdc++.h>
using namespace std;

int countZero(int n)
{
    if (n==0)
    {
        return 0;
    }

    if (n%10 == 0)
    {
       int temp = 1 + countZero(n/10);;
       return temp;
    }
    else
    {
        return countZero(n/10);
    }
    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    cout << countZero(n);
    return 0;
}
