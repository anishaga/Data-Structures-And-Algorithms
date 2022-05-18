#include <bits/stdc++.h>
using namespace std;

int checkValid(string s)
{
    if (s.empty())
    {
        return 1;
    }

    string small = s;

    if (s[0] == 'a')
    {
        if (s[1] == 'a')
        {
            return checkValid(s.substr(1));
        }
        else if (s[1] == 'b')
        {
            return checkValid(s.substr(1));
        }

        if ((s.substr(1)).empty())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (s[0] == 'b')
    {
        if (s[1] == 'b' && s[2] == 'a')
        {
            return checkValid(s.substr(2));
        }

        else if (s[1] == 'b' && (s.substr(2)).empty())
        {
            return 1;
        }
        else
        {
            return 0;
        }
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
    if (s[0] != 'a')
    {
        cout << 0;
    }
    else
    {
        cout << checkValid(s);
    }

    return 0;
}
