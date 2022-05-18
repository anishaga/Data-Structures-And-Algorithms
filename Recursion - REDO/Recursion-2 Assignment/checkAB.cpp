#include <iostream>
using namespace std;

bool checkAB(string s)
{
    if (s.size() == 0)
    {
        return 1;
    }

    if (s[0] == 'a')
    {
        string temp1 = s.substr(1);
        string temp2 = s.substr(1,3);

        if(temp1.size() > 1 && temp2 == "bb")
        {
            return checkAB(s.substr(3));
        } 
        else
        {
            return checkAB(s.substr(1));
        }
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

    string s;
    cin >> s;

    cout << checkAB(s);
    
    return 0;
}