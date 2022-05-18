#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int subset(int input[], int n, int output[][100])
{
    if (n == 0)
    {
        output[0][0] = 0;
        return 1;
    }

    int count = subset(input + 1, n - 1, output);
    int i, j;
    for (i = 0; i < count; i++)
    {
        output[count + i][0] = output[i][0] + 1;
        output[count + i][1] = input[0];
    }

    for (i = 0; i < count; i++)
    {
        for (j = 1; j < output[count + i][0]; j++)
        {
            output[count + i][j + 1] = output[i][j];
        }
    }
    return 2 * count;
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

    inputArray(a, n);

    int output[600][100];
    int size = subset(a, n, output);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}