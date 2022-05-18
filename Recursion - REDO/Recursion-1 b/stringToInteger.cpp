#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int stringToInteger(string s)
{
    if (s.length() == 1)
    {
        return s[0] - 48;
    }

    return ((s[0]-48)*pow(10,s.length()-1)) + stringToInteger(s.substr(1));
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    cout << stringToInteger(s);

    return 0;
}