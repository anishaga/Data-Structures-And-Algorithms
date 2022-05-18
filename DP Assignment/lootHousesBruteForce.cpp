#include <iostream>
using namespace std;

void takeInputArray(int*a, int n)
{
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

int lootHouses(int*a ,int n)
{
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return a[0];
    }

    // int a = lootHouses(a,n-2) + a[n-1];
    // int b= lootHouses(a,n-1);   

    return max (lootHouses(a,n-2) + a[n-1], lootHouses(a,n-1));

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int* a = new int[n];
    takeInputArray(a,n);

    cout << lootHouses(a,n);
    return 0;
}