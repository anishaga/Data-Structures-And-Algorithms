#include <iostream>
#include <string>
using namespace std;

int lengthOfString(string s)
{
    if (s[0] == '\0')
    {
        return 0;
    }

    return 1 + lengthOfString(s.substr(1));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    string s;
    cin >> s;

    cout << lengthOfString(s);

    return 0;
}