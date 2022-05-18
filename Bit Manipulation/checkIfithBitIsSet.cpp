#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int i;
    cin >> i;

    int mask = 1 << i;

    bool set = mask & n;

    cout << set; 

    return 0;
}