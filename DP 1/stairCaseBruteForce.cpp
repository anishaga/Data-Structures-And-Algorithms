#include <iostream>
using namespace std;

int staircase(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }


    int x = staircase(n - 1);
    int y = staircase(n - 2);
    int z = staircase(n - 3);

    return x + y + z;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    cout << staircase(n) << endl;

    return 0;
}

