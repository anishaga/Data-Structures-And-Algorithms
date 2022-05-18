#include <iostream>
using namespace std;

void removeDuplicates(char *s)
{
    if (s[0] == '\0' || s[1] == '\0')
    {
        return;
    }

    if (s[0] == s[1])
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];

        removeDuplicates(s);
    }
    else
    {
        removeDuplicates(s + 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    char *s = new char[100];
    cin >> s;

    removeDuplicates(s);
    cout << s << endl;
    return 0;
}