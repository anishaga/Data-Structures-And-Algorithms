#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int pairSum(int a[], int n, int x)
{
    int sum = 0;
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((a[i] + a[j]) == x)
            {
                sum++;
            }
        }
    }
    return sum;
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

        int x;
        cin >> x;

        cout << pairSum(a, n, x);

        iterations--;
        cout << endl;
    }

    return 0;
}
