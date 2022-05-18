#include <iostream>
#include <string>
using namespace std;

string replacePi(string s)
{
    if (s.size() == 0 || s.size() ==1)
    {
        return s;
    }

    if (s[0] =='p' && s[1] == 'i')
    {
        return "3.14" + replacePi(s.substr(2));
    }

    return s[0] + replacePi(s.substr(1));
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    
    cout << replacePi(s) << endl;

    return 0;
}