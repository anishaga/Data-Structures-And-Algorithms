#include <iostream>
#include <unordered_map>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int pairsWithDifference(int a[], int n, int k)
{
    int count = 0;
    unordered_map<int, int> ourMap;

    for (int i = 0; i < n; i++)
    {

        if (ourMap.count(a[i] - k) == 1)
        {
            count = count + ourMap[a[i] - k];
        }

        if (ourMap.count(a[i] + k) == 1)
        {
            if (k != 0)
            {
            count = count + ourMap[a[i] + k];
            }
        }

        if (ourMap.count(a[i]) == 1)
        {
            ourMap[a[i]] = ourMap[a[i]] + 1;
        }
        else
        {
            ourMap[a[i]] = 1;
        }
    }
 
    return count;
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

    int k;
    cin >> k;

    cout << pairsWithDifference(a, n, k);

    return 0;
}