#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    //const int i=69;
    int const i = 69;
    cout << i << endl;

    int j = 69;
    //const int &k = j;
    int const &k = j;
    j++;
    cout << k;

    return 0;
}
