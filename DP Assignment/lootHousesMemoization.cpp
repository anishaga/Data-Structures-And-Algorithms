#include <iostream>
using namespace std;

void takeInputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int lootHouses(int *a, int *ans, int n)
{
    if (ans[n] != -1)
    {
        return ans[n];
    }

    ans[n] = max(lootHouses(a, ans, n - 2) + a[n - 1], lootHouses(a, ans, n - 1));
    return ans[n];
}

int lootHouses(int *a, int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = a[0];
    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return lootHouses(a, ans, n);
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