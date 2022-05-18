#include <iostream>
using namespace std;

void takeInputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int lootHouses(int *a, int n)
{
    int *dp = new int[n + 1];

    dp[0] = 0;
    dp[1] = a[0];

    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = max(dp[i - 2] + a[i - 1], dp[i - 1]);
    }
    return dp[n];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int *a = new int[n];
    takeInputArray(a, n);

    cout << lootHouses(a, n);
    return 0;
}