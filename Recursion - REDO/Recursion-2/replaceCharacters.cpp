#include <iostream>
using namespace std;

void replaceChar(char* s, char c1, char c2)
{
    if (s[0] == '\0')
    {
        return;
    }

    if (s[0] == c1)
    {
        s[0] = c2;
    }

    replaceChar(s+1,c1,c2);
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    char* s = new char[100];
    cin >> s;

    char c1;
    cin >> c1;

    char c2;
    cin >> c2;

    replaceChar(s,c1,c2);

    cout << s << endl;

    return 0;
}