#include <bits/stdc++.h>
using namespace std;

int subsequence(string s, string op[])
{
    if (s.empty())
    {
        op[0]="";
        return 1;
    }

    string smallString = s.substr(1); 
    int size = subsequence(smallString,op);
    for (int i=0; i<size; i++)
    {
        op[size+i] = s[0] + op[i];
    }
    
    return size*2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    getline(cin, s);

    int temp = s.size();
    temp = pow(2, temp);
    string *op = new string[temp];

    int count = subsequence(s, op);

    for (int i = 0; i < count; i++)
    {
        cout << op[i]<<endl;
    }

    return 0;
}