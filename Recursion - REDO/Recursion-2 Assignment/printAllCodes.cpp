#include <iostream>
#include <string>
using namespace std;

int atoi(char a)
{
    int i = a - '0';
    return i;
}

char itoa(int i)
{
    char c = 'a' + i - 1;
    return c;
}

void printAllCodes(string s, string output)
{
    if (s.size() <= 0)
    {
        cout << output << endl;
        return;
    }

    string newOut1;
    newOut1 = output + itoa(atoi(s[0]));

    string newOut2;
    newOut2 = output + itoa(10 * atoi(s[0]) + atoi(s[1]));

    printAllCodes(s.substr(1), newOut1);
    if (s.size() > 1)
    {

        if (10 * atoi(s[0]) + atoi(s[1]) >= 10 && 10 * atoi(s[0]) + atoi(s[1]) <= 26)
        {
            printAllCodes(s.substr(2), newOut2);
        }
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
    printAllCodes(s, output);

    return 0;
}