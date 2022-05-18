#include <iostream>
using namespace std;

int countOne(int **cake, int n, int i, int j, bool **visited)
{
    if (i < 0 || i >= n || j < 0 || j >= n || cake[i][j] == 0)
    {
        return 0;
        
    }
    if (visited[i][j])
    {
        return 1;
    }

    visited[i][j] = 1;

    int ans = countOne(cake, n, i + 1, j, visited);
    ans = ans + countOne(cake, n, i - 1, j, visited);
    ans = ans + countOne(cake, n, i, j - 1, visited);
    ans = ans + countOne(cake, n, i, j + 1, visited);

    return ans;
}

int countOne(int **cake, int n)
{
    bool **visited = new bool *[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && cake[i][j] == 1)
            {
                count = max(count, countOne(cake, n, i, j, visited));
            }
        }
    }
    return 1 + count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int **cake = new int *[n];
    for (int i = 0; i < n; i++)
    {
        cake[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> cake[i][j];
        }
    }

    cout << countOne(cake, n);

    return 0;
}