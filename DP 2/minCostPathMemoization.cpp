#include <iostream>
#include <climits>
using namespace std;

int minCostPathMemoization(int **mat, int m, int n, int x, int y, int **output)
{
    if (x >= m || y >= n)
    {
        return INT_MAX;
    }

    if (output[x][y] != -1)
    {
        return output[x][y];
    }

    int a = minCostPathMemoization(mat, m, n, x + 1, y, output);
    int b = minCostPathMemoization(mat, m, n, x, y + 1, output);
    int c = minCostPathMemoization(mat, m, n, x + 1, y + 1, output);

    output[x][y] = min(a,min(b,c)) + mat[x][y];

    return output[x][y];
}

int minCostPathMemoization(int **a, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }

    output[m - 1][n - 1] = a[m - 1][n - 1];

    return minCostPathMemoization(a, m, n, 0, 0, output);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int m;
    cin >> m;

    int n;
    cin >> n;

    int **a = new int *[m];

    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << minCostPathMemoization(a, m, n);

    return 0;
}