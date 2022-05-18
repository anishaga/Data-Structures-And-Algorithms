#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void pairSum(int a[], int n)
{
    unordered_map<int, bool> indexMap;
    int count = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (indexMap.count(a[i] * -1) == 1)
        {
            count++;
        }
        indexMap[a[i]] = 1;
    }

    cout << count << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int a[100];
    takeInputArray(a, n);
    pairSum(a,n);
    return 0;
}