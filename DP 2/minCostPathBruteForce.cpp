#include <iostream>
#include <climits>
using namespace std;

int minCostPath(int** mat, int m, int n, int x, int y)
{
    if (x == m - 1 && y == n - 1)
    {
        return mat[m - 1][n - 1];
    }

    if (x >= m || y >= n)
    {
        return INT_MAX;
    }

    int a = minCostPath(mat, m, n, x + 1, y + 1);
    int b = minCostPath(mat, m, n, x, y + 1);
    int c = minCostPath(mat, m, n, x + 1, y);

    return mat[x][y] + min(a, min(b, c));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int r;
    cin >> r;

    int c;
    cin >> c;

    int **m = new int*[r];

    for (int i = 0; i < r; i++)
    {
        m[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            cin >> m[i][j];
        }
    }

    cout << minCostPath(m, r, c, 0, 0) << endl;

    return 0;
}