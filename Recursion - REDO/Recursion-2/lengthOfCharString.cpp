#include <iostream>
using namespace std;

int lengthOfString(char *s)
{
    if (s[0] == '\0')
    {
        return 0;
    }

    return 1 + lengthOfString(s + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    char *s = new char[100];
    cin >> s;

    cout << lengthOfString(s);

    return 0;
}