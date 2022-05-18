#include <iostream>
#include <string>
using namespace std;

int LcsMemoization(string s, string t, int **ans)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    if (ans[s.size()][t.size()] != -1)
    {
        return ans[s.size()][t.size()];
    }

    if (s[0] == t[0])
    {
        ans[s.size()][t.size()] = 1 + LcsMemoization(s.substr(1), t.substr(1), ans);
        return ans[s.size()][t.size()];
    }
    else
    {
        int a = LcsMemoization(s.substr(1), t, ans);
        int b = LcsMemoization(s, t.substr(1), ans);
        ans[s.size()][t.size()] = max(a, b);
        return ans[s.size()][t.size()];
    }
}

int LcsMemoization(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **ans = new int *[m + 1];

    for (int i = 0; i <= m; i++)
    {
        ans[i] = new int[n + 1];

        for (int j = 0; j <= n; j++)
        {
            ans[i][j] = -1;
        }
    }

    return LcsMemoization(s, t, ans);
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

    cout << LcsMemoization(s, t) << endl;

    return 0;
}