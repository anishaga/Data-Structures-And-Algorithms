#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int tripletSum(int a[], int n, int x)
{
    int i, j, k;
    int count = 0;

    for (i = 0; i < n - 2; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                if ((a[i] + a[j] + a[k]) == x)
                {
                    count++;
                }
            }
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

        cout << tripletSum(a, n, x);

        iterations--;
        cout << endl;
    }

    return 0;
}
