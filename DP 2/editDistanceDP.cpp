#include <iostream>
#include <string>
using namespace std;

int editDistanceDP(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **dp = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        dp[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = max(i, j);
            }
            else
            {
                if (s[m - i] == t[n - j])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
    }

    return dp[m][n];

    // Filling The Remaining Cells
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    string t;
    cin >> t;

    cout << editDistanceDP(s, t);
    return 0;
}