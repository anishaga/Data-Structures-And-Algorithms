#include <bits/stdc++.h>
using namespace std;

void sub(string ip, string op)
{
    if (ip.empty())
    {
        cout << op << endl;
        return;
    }
    sub(ip.substr(1), op);
    sub(ip.substr(1), op + ip[0]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    string op = "";

    sub(s, op);

    return 0;
}
