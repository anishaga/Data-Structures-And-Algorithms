#include <iostream>
using namespace std;

int countZeros(int n)
{
    if (n / 10 == 0)
    {
        return 0;
    }

    int ans = countZeros(n / 10);

    if (n % 10 == 0)
    {
        ans = ans + 1;
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << countZeros(n) << endl;

    return 0;
}