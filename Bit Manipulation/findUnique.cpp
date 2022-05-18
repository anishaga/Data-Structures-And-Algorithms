#include <iostream>
using namespace std;

void takeInputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
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

    int XOR = 0;

    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ a[i];
    }

    cout << XOR;

    return 0;
}