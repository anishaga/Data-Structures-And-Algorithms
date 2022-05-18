#include <iostream>
#include <stdio.h>
using namespace std;

int checkstring(char *t)
{
    if (*t == NULL)
    {
        return 1;
    }
    char *c = t;
    if (*t == 'a')
    {
        if (*(c + 1) == 'a')
        {

            return checkstring(t + 1);
        }
        else if (*(c + 1) == 'b')
        {
            return checkstring(t + 1);
        }
        
        if (*(c + 1) == NULL)
        {

            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (*t == 'b')
    {
        if (*(c + 1) == 'b' && *(c + 2) == 'a')
        {
            return checkstring(t + 2);
        }
        else if (*(c + 1) == 'b' && *(c + 2) == NULL)
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
    char s[100];
    cin >> s;
    char *t;
    t = s;
    if (*t == 'a')
    {
        t = t++;

        if (checkstring(t))
        {
            cout << "valid substring";
        }
        else
        {
            cout << "Not a valid substring";
        }
    }
    else
    {
        cout << "Not a valid substring";
    }
    return 0;
}
