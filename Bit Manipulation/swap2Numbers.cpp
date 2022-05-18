#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int a, b;
    cin >> a >> b;

    a = a ^ b;
    b = a ^ b; // (a^b)^b = a
    a = a ^ b; // (a^b)^a = b

    cout << a << " " << b << endl;
    return 0;
}