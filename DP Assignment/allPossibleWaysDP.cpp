#include <iostream>
#include <cmath>
using namespace std;

int allPossibleWays(int a, int b)
{
    int **dp = new int *[a + 1];
    int temp = a / 2;
    for (int i = 0; i < a + 1; i++)
    {
        dp[i] = new int[temp];
    }

    //Filling First Row
    for (int j=0; j<temp; j++)
    {

    }

    return allPossibleWays(a, b, 1, dp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int a;
    cin >> a;

    int b;
    cin >> b;

    cout << allPossibleWays(a, b);
    return 0;
}