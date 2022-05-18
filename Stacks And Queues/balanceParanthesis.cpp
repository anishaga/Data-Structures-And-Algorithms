#include <bits/stdc++.h>
using namespace std;
#include <stack>

bool checkBalance(string p)
{
    stack<char> s;

    int i = 0;
    while (p[i] != '\0')
    {
        if (p[i] == '(' || p[i] == '{' || p[i] == '[')
        {
            s.push(p[i]); 
        }

        else if (p[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return 0;
            }
        }

        else if (p[i] == '}')
        {
            if (s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return 0;
            }
        }
        else if (p[i] == ']')
        {
            if (s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return 0;
            }
        }
        i++;
    }
    if (s.size() == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string p;
    cin >> p;
    cout << checkBalance(p);
    return 0;
}
