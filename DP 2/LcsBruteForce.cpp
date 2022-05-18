#include <iostream>
#include <string>
using namespace std;

int LCS(string s, string t)
{
    if (s.size() == 0 || t.size() == 0)
    {
        return 0;
    }

    if (s[0] == t[0])
    {
        return 1 + LCS(s.substr(1), t.substr(1));
    }
    else
    {
        int a = LCS(s.substr(1), t);
        int b = LCS(s, t.substr(1));
        // int c = LCS(s.substr(1), t.substr(1)); // Redundant Call

        // return max(a, max(b, c));
        return max(a,b);
    }
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

    cout << LCS(s, t) << endl;
    return 0;
}