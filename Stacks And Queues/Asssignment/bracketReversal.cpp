#include <bits/stdc++.h>
using namespace std;
#include <stack>

int length(string s)
{
    int i = 0;
    int count = 0;
    while (s[i] != '\0')
    {
        i++;
        count++;
    }
    return count;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    if (length(s) % 2 != 0)
    {
        cout << -1;
    }
    else
    {
        int count = 0;
        stack<int> s1;
        int i = 0;
        while (s[i] != '\0')
        {
            if (s[i] == '{')
            {
                s1.push(s[i]);
            }
            else if (s[i] == '}')
            {
                if (s1.empty())
                {
                    s1.push(s[i]);
                }
                else if (s1.top() == '{')
                {
                    s1.pop();
                }
                else
                {
                    s1.push(s[i]);
                }
            }
            i++;
        }
        if (s1.empty())
        {
            cout << 0;
        }
        else
        {
            while (s1.size() != 0)
            {
                char c1, c2;
                c1 = s1.top();
                s1.pop();
                c2 = s1.top();
                s1.pop();

                if (c1 == c2)
                {
                    count++;
                }
                else
                {
                    count++;
                    count++;
                }
            }
            cout << count;
        }
    }
    return 0;
}
