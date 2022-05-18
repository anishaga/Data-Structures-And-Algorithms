#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int checkRotation(int a[], int n)
{
    int temp = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > temp)
        {
            temp = a[i];
        }
        else
        {
            return i;
        }
    }
    return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int iterations;
    cin >> iterations;

    while (iterations > 0)
    {
        int n;
        cin >> n;
        int a[100];
        inputArray(a, n);

        cout << checkRotation(a, n);

        iterations--;
        cout << endl;
    }
    return 0;
}
