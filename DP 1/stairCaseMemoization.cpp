#include <iostream>
using namespace std;

int staircase(int n, int* ans)
{
    if (n < 0)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int x = staircase(n - 1,ans);
    int y = staircase(n - 2,ans);
    int z = staircase(n - 3,ans);

    ans[n] = x + y + z;
    return ans[n];
}

int staircase (int n)
{
    int * ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;

    for (int i=2; i<n+1; i++)
    {
        ans[i] = -1;
    }

    return staircase(n,ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    cout << staircase(n) << endl;

    return 0;
}

