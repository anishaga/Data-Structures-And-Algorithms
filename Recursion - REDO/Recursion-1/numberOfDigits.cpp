#include <iostream>
using namespace std;

int numberOfDigits(int n)
{
    if (n/10 == 0)
    {
        return 1;
    }

    return 1 + numberOfDigits(n/10);
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << numberOfDigits(n);
    return 0;
}