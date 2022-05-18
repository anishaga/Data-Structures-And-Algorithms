#include <iostream>
#include <cmath>
using namespace std;

float geometricSum(int k)
{
    if (k==0)
    {
        return 1.0;
    }

    return geometricSum(k-1) + (1.0/pow(2,k));


}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int k;
    cin >> k;

    cout << geometricSum(k) << endl;
    return 0;
}