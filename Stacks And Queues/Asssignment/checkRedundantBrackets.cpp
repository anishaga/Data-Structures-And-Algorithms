#include <bits/stdc++.h>
using namespace std;
#include <stack>

bool checkBracket(string s)
{
    stack<char> s1;
    char prev = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] != ')')
        {
            s1.push(s[i]);
        } 

        else if (s[i] == ')')
        {
            int count = 0;
            while (s1.top() != '(')
            {
                s1.pop();
                count++;
            }

            if (count < 2)
            {
                return 1;
            }
            s1.pop();
        }

        i++;
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    cout << checkBracket(s);
    return 0;
}
