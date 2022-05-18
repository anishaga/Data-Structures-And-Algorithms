#include <iostream>
#include <string>
using namespace std;

int keypad(int n, string* output, string s[])
{
    if (n == 0)
    {
        output[0] = "";
        return 1;
    }

    int len = keypad(n / 10, output, s);
    string temp = s[n % 10];

    int size = temp.size() - 1; //Reduced Size So That While Copying, Can Copy One Less Time
    int dump = len;
    while (size != 0)
    {
        for (int j = dump; j < dump + len; j++)
        {
            output[j] = output[j - len];
        }
        size--;
        dump = dump + len;
    }

    size = temp.size();
    int i = 0;
    int g = len;
    for (int j = 0; j < dump; j++)
    {
        if (j == len)
        {
            i++;
            len = len + g;
        }
        output[j] = output[j] + temp[i];
    }
    return dump;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    string *output = new string[1000];
    string s[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int size = keypad(n, output, s);

    for (int i = 0; i < size; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}