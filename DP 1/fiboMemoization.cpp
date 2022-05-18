#include <iostream>
using namespace std;

//Memoization -> Top-Down Approach
int fibo (int n, int* ans)
{
    if (n <=1)
    {
        return n;
    }

    //Check If Output Already Exists

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int a = fibo(n-1,ans);
    int b = fibo(n-2,ans);

    ans[n] = a+b;  //Saving Answer For Future Use :)

    return ans[n];
}

int fibo(int n)
{
    int *ans = new int[n+1];

    for (int i=0; i<n+1; i++)
    {
        ans[i] = -1;
    }

    return fibo (n,ans);
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