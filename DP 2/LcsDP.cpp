#include <iostream>
#include <string>
using namespace std;

// int LcsDP(string s, string t)
// {
//     int m = s.size();
//     int n = t.size();

//     int **dp = new int *[m + 1];

//     for (int i = 0; i < m + 1; i++)
//     {
//         dp[i] = new int[n + 1];
//         for (int j = 0; j < n + 1; j++)
//         {
//             if (i == 0 || j == 0)
//             {
//                 dp[i][j] = 0;
//             }
//             else
//             {
//                 if (s[m - i] == t[n - j])
//                 {
//                     dp[i][j] = 1 + dp[i - 1][j - 1];
//                 }
//                 else
//                 {
//                     dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
//                 }
//             }
//         }
//     }

//     return dp[m][n];
// }

int LcsDP(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **dp = new int *[m + 1];

    for (int i = 0; i < m + 1; i++)
    {
        dp[i] = new int[n + 1];
    }

    // Filling First Column With Zero

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    // Filling First Row With Zero

    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    // Filling Rest Of The Elements

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                int c = dp[i - 1][j - 1];

                dp[i][j] = max(a, max(b, c));
            }
        }
    }
    return dp[m][n];
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

    cout << LcsDP(s, t) << endl;
    return 0;
}