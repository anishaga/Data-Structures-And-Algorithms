#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string s, string *ans)
{
    if (s.size() == 0)
    {
        ans[0] = "";
        return 1;
    }

    string copy[1000];
    int size = returnPermutations(s.substr(1), copy);
 
    int it = 0;
    for (int i = 0; i < size; i++)
    {
        int index = 0;
        for (int j = 0; j <= copy[i].size(); j++)
        {
            ans[it++] = copy[i].substr(0, j) + s[0] + copy[i].substr(j);
        }
    }

    return it;
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

    int size = returnPermutations(s, ans);

    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}