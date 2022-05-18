#include <bits/stdc++.h>
using namespace std;

// int printNum(int n)
// {
//     if (n == 1)
//     {
//         cout << "1 ";
//         return 2;
//     }

//     int temp = printNum(n - 1);
//     cout << temp << " ";
//     return temp + 1;
// }

void printNum(int n)
{
    if (n == 0)
    {
        cout << "0 ";
        return;
    }

    printNum(n-1);
    cout << n  << " ";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    printNum(n);
    return 0;
}
