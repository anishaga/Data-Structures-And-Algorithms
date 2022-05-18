#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char a, char b, char c)
{

    if (n == 1)
    {
        cout << a << " " << c << endl;
        return;
    }

    towerOfHanoi(n - 1, a, c, b);
    cout << a << " " << c << endl;
    towerOfHanoi(n - 1, b, a, c);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    towerOfHanoi(n, 'a', 'b', 'c');

    return 0;
}
