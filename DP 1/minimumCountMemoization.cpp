#include <iostream>
#include <cmath>
using namespace std;

int minimumCount(int n, int* ans)
{
    if (n==0)    
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int temp = sqrt(n);
    int minimum = INT_MAX;

    for (int i = 1; i <= temp; i++)
    {
        minimum = min(minimum,minimumCount(n-(i*i),ans));
    }

    return 1 + minimum;
}

int minimumCount(int n)
{
    int* ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;

    for (int i=2 ; i<n+1 ; i++)
    {
        ans[i] = -1;
    }

    return minimumCount(n,ans);
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << minimumCount(n) << endl;
    return 0;
}