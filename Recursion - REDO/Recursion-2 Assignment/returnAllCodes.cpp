#include <iostream>
#include <string>

using namespace std;

int atoi(char a)
{
    int i = a - '0';
    return i;
}
char itoa(int i)
{
    char c = 'a' + i - 1;
    return c;
}

int returnAllCodes(string s, string *ans)
{
    if (s.size() == 0)
    {
        return 1;
    }

    if (s.size() == 1)
    {
        ans[0] = itoa(atoi(s[0]));
        return 1;
    }

    string temp1[1000];
    string temp2[1000];
    int s1 = returnAllCodes(s.substr(1), temp1);
    int s2 = 0;

    if (s.size() > 1)
    {
        if (10*atoi(s[0]) + atoi (s[1]) >= 10 && 10*atoi(s[0]) + atoi (s[1]) <=26)
        {
            s2 = returnAllCodes(s.substr(2), temp2);
        }
    }

    int k = 0;

    for (int i=0; i<s1; i++)
    {
        ans[k++] = itoa(atoi(s[0])) + temp1[i]; 
    }

    for (int i=0; i<s2; i++)
    {
        ans[k++] = itoa(10*atoi(s[0]) + atoi(s[1])) + temp2[i];
    }

    return k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    string *ans = new string[1000];
    int size = returnAllCodes(s, ans);

    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}