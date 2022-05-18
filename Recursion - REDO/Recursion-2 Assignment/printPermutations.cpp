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

void printPermutations(string s, string output)
{
    if (s.size() == 0)
    {
        cout << output << endl;
    }

    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        string newOut = output + s[i];
        string temp = s.substr(0, i) + s.substr(i + 1);
        printPermutations(temp, newOut);
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
    string output = "";

    printPermutations(s, output);

    return 0;
}