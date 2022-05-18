#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void rotateArray(int a[], int n, int x)
{
    while (x > 0)
    {
        int temp = a[0];
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        a[n - 1] = temp;
        x--;
    }
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
        int a[100];
        int n;
        cin >> n;

        inputArray(a, n);

        int x;
        cin >> x;
        rotateArray(a, n, x);

        printArray(a, n);

        iterations--;
        cout << endl;
    }

    return 0;
}
