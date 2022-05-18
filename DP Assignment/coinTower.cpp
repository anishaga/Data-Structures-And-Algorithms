#include <iostream>
using namespace std;

bool coinTower(int n, int x, int y)
{
    if (n == 1 || n == x || n == y)
    {
        return 1;
    }

    int ans;

    if (n > x && n > y)
    {
        ans = !coinTower(n - 1, x, y) || !coinTower(n - x, x, y) || !coinTower(n - y, x, y) ;
    }
    else if (n > x && n < y)
    {
        ans = !coinTower(n - 1, x, y) || !coinTower(n - x, x, y);
    }
    else if (n<x && n<y)
    {
        ans = !coinTower(n - 1, x, y) || !coinTower(n - y, x, y) ;
    }
    else
    {
        ans = !coinTower(n-1,x,y);
    }

    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n, x, y;
    cin >> n >> x >> y;

    bool ans = coinTower(n, x, y);
    if (ans)
    {
        cout << "Beerus";
    }
    else
    {
        cout << "Whis";
    }
    return 0;
}