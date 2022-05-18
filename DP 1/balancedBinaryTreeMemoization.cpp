#include <iostream>
#include <cmath>
using namespace std;

int numberOfBT(int h, int *ans)
{
    if (h <= 1)
    {
        return 1;
    }

    if (ans[h] != -1)
    {
        return ans[h];
    }

    int mod = pow(10, 9) + 7;

    int x = numberOfBT(h - 1, ans);
    int y = numberOfBT(h - 2, ans);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);

    ans[h] = (temp1 + temp2)%mod;
    return ans[h];
}

int numberOfBT(int h)
{
    int *ans = new int[h + 1];
    ans[0] = 1;
    ans[1] = 1;

    for (int i = 2; i < h + 1; i++)
    {
        ans[i] = -1;
    }

    return numberOfBT(h, ans);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int h;
    cin >> h;

    cout << numberOfBT(h);

    return 0;
}