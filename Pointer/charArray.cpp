#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    char st[] = "ABCD";
    int i = 0;
    cout << *(st + i) << endl;
    cout << *(st) << endl;
    cout << st[i] << endl;
    cout << i[st] << endl;
    cout << *(st) + i << endl;

    //   for(int i = 0; st[i] != ‘\0’; i++) {
    //      cout << st[i] << *(st)+i << *(i+st) << i[st];
    //   }

    return 0;
}
