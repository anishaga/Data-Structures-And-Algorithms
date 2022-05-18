#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string extractUnique(string s)
{

    unordered_map<char, bool> ourMap;

    for (int i = 0; i < s.length(); i++)
    {
        if (ourMap.count(s[i]) == 0)
        {
            ourMap[s[i]] = 1;
        }
        else
        {
            s.erase(i,1);
            i--;
        }
    }
    return s;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;

    cout << extractUnique(s);

    return 0;
}