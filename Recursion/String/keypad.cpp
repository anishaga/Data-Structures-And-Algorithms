#include <bits/stdc++.h>
using namespace std;

int seq(int n, string op[])
{
    if (n == 0 || n == 1)
    {
        op[0] = "";
        return 1;
    }

    string s[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string dump = s[n % 10];

    int size = seq(n / 10, op);

    int j = 1;
    int i = size;
    int temp = size;
    int k = 0;
    while (j < dump.size())
    {
        temp = size + temp;
        k = 0;
        for (; i < temp; i++)
        {
            op[i] = op[k];
            k++;
        }
        j++;
    }

    j = 0;
    i = 0;
    temp = size;
    while (j < dump.size())
    {
        for (; i < size; i++)
        {
            op[i] = op[i] + dump[j];
        }
        j++;
        size = size + temp;
    }

    size = size - temp;
    return size;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    string *op = new string[1000];

    int size = seq(n, op);

    for (int i = 0; i < size; i++)
    {
        cout << op[i] << endl;
    }

    return 0;
}