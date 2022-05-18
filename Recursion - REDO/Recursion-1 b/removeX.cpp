#include <iostream>
#include <string>
using namespace std;

string removeX(string s)
{
    if (s.size() == 0)
    {
        return s;
    }

    if(s[0] == 'x')
    {
        return removeX(s.substr(1));
    }

    return s[0] + removeX(s.substr(1));
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    
    cout << removeX(s) << endl;
    return 0;
}