#include <iostream>
using namespace std;

int xToThePowerN(int x, int n)
{
    if (n<=0)
    {
        return 1;
    }

    return xToThePowerN(x,n-1)*x;

}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int x;
    cin >> x;

    int n;
    cin >> n;

    cout << xToThePowerN(x,n) << endl;
    return 0;
}