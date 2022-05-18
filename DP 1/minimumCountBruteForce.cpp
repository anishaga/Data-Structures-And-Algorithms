#include <iostream>
#include <cmath>
using namespace std;

int minimumCount(int n)
{
    if (n==0)    
    {
        return 0;
    }

    int temp = sqrt(n);
    int minimum = INT_MAX;

    for (int i = 1; i <= temp; i++)
    {
        minimum = min(minimum,minimumCount(n-(i*i)));
    }

    return 1 + minimum;
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << minimumCount(n) << endl;
    return 0;
}