#include <iostream>
using namespace std;

int minSteps(int n)
{
    if (n == 1)
    {
        return 0;
    }
    int x = INT_MAX;
    int y = INT_MAX;
    int z = INT_MAX;
    
    x = minSteps(n - 1);

    if (n % 3 == 0)
    {
        y = minSteps(n / 3);
    }

    if (n % 2 == 0)
    {
        z = minSteps(n / 2);
    }

    return 1 + min(x, min(y, z));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << minSteps(n) << endl;

    return 0;
}