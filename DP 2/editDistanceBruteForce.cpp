#include <iostream>
#include <string>
using namespace std;

int editDistance(string s, string t)
{
    int m = s.size();
    int n = t.size();

    if (m == 0 || n == 0)
    {
        return max(m,n);
    }

    if (s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }
    else
    {
        // Insert
        int a = 1 + editDistance(s.substr(1), t);
        // Delete
        int b = 1 + editDistance(s, t.substr(1));
        // Replace
        int c = 1 + editDistance(s.substr(1), t.substr(1));

        return min(a, min(b, c));
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

    cout << editDistance(s, t) << endl;

    return 0;
}