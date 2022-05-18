#include <iostream>
#include <string>
using namespace std;

int editDistanceMemoization(string s, string t, int **ans)
{
    int m = s.size();
    int n = t.size();

    if (m == 0 || n == 0)
    {
        return max(m, n);
    }

    if (ans[m][n] != -1)
    {
        return ans[m][n];
    }

    if (s[0] == t[0])
    {
        ans[m][n] = editDistanceMemoization(s.substr(1), t.substr(1), ans);
        return ans[m][n];
    }
    else
    {
        //Insert
        int a = 1 + editDistanceMemoization(s.substr(1), t, ans);
        //Delete
        int b = 1 + editDistanceMemoization(s, t.substr(1), ans);
        //Replace
        int c = 1 + editDistanceMemoization(s.substr(1), t.substr(1), ans);

        ans[m][n] = min(a,min(b,c));
        return ans[m][n];
    }
}

int editDistanceMemoization(string s, string t)
{
    int m = s.size();
    int n = t.size();

    int **ans = new int *[m + 1];

    for (int i = 0; i < m + 1; i++)
    {
        ans[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            ans[i][j] = -1;
        }
    }

    return editDistanceMemoization(s, t, ans);
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

    cout << editDistanceMemoization(s, t) << endl;

    return 0;
}