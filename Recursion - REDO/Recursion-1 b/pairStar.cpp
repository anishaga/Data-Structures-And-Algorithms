#include <iostream>
#include <string>
using namespace std;

string pairStar(string s)
{
    if (s.length() == 0)
    {
        return s;
    }

    if (s[0] == s[1])
    {
        string smallOutput;
        smallOutput = s[0];
        smallOutput = smallOutput + "*";
        return smallOutput + pairStar(s.substr(1));
    }

    return s[0] + pairStar(s.substr(1));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    cout << pairStar(s) << endl;

    return 0;
}