#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void intArray(int arr1[], int n, int arr2[], int m)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        int temp = arr2[i];
        int flag = 0;

        for (j = 0; j < n; j++)
        {
            if (arr1[j] == temp)
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            cout << temp << " ";
        }
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

        int n;
        cin >> n;
        int arr1[100];
        inputArray(arr1, n);

        int m;
        cin >> m;
        int arr2[100];
        inputArray(arr2, m);

        intArray(arr1, n, arr2, m);

        iterations--;
        cout << endl;
    }

    return 0;
}
