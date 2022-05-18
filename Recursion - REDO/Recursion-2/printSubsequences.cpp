#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void printSubsequences(string s, string output)
{
    if (s.size() == 0)
    {
        cout << output << endl;
        return;
    }

    printSubsequences(s.substr(1), output);
    printSubsequences(s.substr(1), output + s[0]);
}

// int printSubsequences(string s, string* output)
// {
//     if (s.length() == 0)
//     {
//         output[0] = " " ;
//         cout << output[0] << endl;
//         return 1;
//     }
//         int len = printSubsequences(s.substr(1),output);

//         for (int i = len; i<2*len; i++)
//         {
//             output[i] = s[0] + output[i - len];
//             cout << output[i] << endl;
//         }

//         return 2*len;
// }

// void printSubsequences(string s)
// {
//     int len = pow(2,s.length());
//     string* output = new string[len];
//     printSubsequences(s,output);
// }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    string output = "";
    printSubsequences(s, output);

    return 0;
}