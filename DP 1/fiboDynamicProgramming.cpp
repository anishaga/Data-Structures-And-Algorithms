#include <iostream>
using namespace std;

int fibo (int n)
{
    int * ans = new int[n+1];

    ans[0] = 0;
    ans[1] = 1;

    for (int i=2; i<n+1; i++)
    {
        ans[i] = ans[i-1] + ans[i-2];
    } 
    return ans[n];
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << fibo(n);
    return 0;
}