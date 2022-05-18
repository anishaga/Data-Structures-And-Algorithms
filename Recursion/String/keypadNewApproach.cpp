#include <bits/stdc++.h>
using namespace std;

void seq(int n, string op)
{
    if (n == 0 || n == 1)
    {
        cout<<op<<endl;
        return;
    }

    string s[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string dump = s[n % 10];
    
    int j=0;
    while (j< dump.size())
    {
    seq(n/10, op+ dump[j]);
    j++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    string op = "";

    seq(n, op);
    return 0;
}
