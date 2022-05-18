#include <iostream>
#include <string>
using namespace std;

int shortestSub(string s, string v)
{
    if (s.size() == 0 )
    {
        return 1005;
    }

    if (v.size() <= 0)
    {
        return 1;
    }
    int i = 0;
    for (; i < v.size(); i++)
    {
        if (v[i] == s[0])
        {
            break;
        }
    }
    if (i==v.size())
    {
        return 1;
    }

    return min(shortestSub(s.substr(1), v), 1 + shortestSub(s.substr(1), v.substr(i + 1)));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s, v;
    cin >> s >> v;

    cout << shortestSub(s, v) << endl;

    return 0;
}