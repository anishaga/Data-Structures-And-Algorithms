#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n, i;
    cin >> n >> i;

    int mask = 1 << i;

    int num = n | mask;

    cout << num;

    return 0;
}