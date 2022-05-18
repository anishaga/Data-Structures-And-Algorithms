#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n/10 == 0)
    {
        return n;
    }

    return n%10 + sumOfDigits(n/10);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << sumOfDigits(n) << endl;

    return 0;
}