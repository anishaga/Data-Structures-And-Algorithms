#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int subsequences(string s, string* ans)
{
    if(s.size() == 0)
    {
        ans[0] = "";
        return 1;
    }

    int len = subsequences(s.substr(1),ans);
    
    for (int i = len; i<len*2; i++)
    {
        ans[i] = s[0] + ans[i-len];
    }
    return len*2;
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    int len = pow(2,s.size());  
    string* ans = new string[len];

    int size = subsequences(s,ans);

    for (int i=0; i<size; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}