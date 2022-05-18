#include <iostream>
#include <climits>
using namespace std;

void takeInputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
int LIS(int *a, int n)
{
    int *dp = new int[n];
    // dp[0] = 1;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j <i ; j++)
        {
            if (a[i] > a[j])
            {
                if (max < dp[j] )
                {
                    max = dp[j];
                }
            }
        }
        dp[i] = max +1;
        if (dp[i] > ans)
        {
            ans = dp[i];
        }
    }

    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int *a = new int[n];
    takeInputArray(a, n);

    cout << LIS(a, n);
    return 0;
}