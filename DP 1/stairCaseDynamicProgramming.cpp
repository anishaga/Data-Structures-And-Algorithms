#include <iostream>
using namespace std;

int staircase (int n)
{
    int * ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;

    for (int i=3; i<n+1; i++)
    {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
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

    cout << staircase(n) << endl;

    return 0;
}

