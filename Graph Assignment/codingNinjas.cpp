#include <iostream>
#include <string>
using namespace std;

bool pathFinder(char **matrix, int n, int m, string s, int i, int j, bool **visited)
{
    if (s.size() == 0)
    {
        return 1;
    }

    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return 0;
    }

    if (visited[i][j] == 1)
    {
        return 0;
    }

    if (s[0] != matrix[i][j])
    {
        return 0;
    }

    visited[i][j] = 1;

    int ans = pathFinder(matrix, n, m, s.substr(1), i - 1, j - 1, visited);
    ans = ans || pathFinder(matrix, n, m, s.substr(1), i - 1, j, visited);
    ans = ans || pathFinder(matrix, n, m, s.substr(1), i - 1, j + 1, visited);
    ans = ans || pathFinder(matrix, n, m, s.substr(1), i, j + 1, visited);
    ans = ans || pathFinder(matrix, n, m, s.substr(1), i, j - 1, visited);
    ans = ans || pathFinder(matrix, n, m, s.substr(1), i + 1, j + 1, visited);
    ans = ans || pathFinder(matrix, n, m, s.substr(1), i + 1, j, visited);
    ans = ans || pathFinder(matrix, n, m, s.substr(1), i + 1, j - 1, visited);
    visited[i][j] = 0;
    return ans;
}

bool pathExists(char **matrix, int n, int m)
{
    string s = "CODINGNINJA";

    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 'C')
            {
                if (pathFinder(matrix, n, m, s, i, j, visited))
                {
                    return 1;
                }
            }
        }
    }

    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    char **matrix = new char *[n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new char[m];
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << pathExists(matrix, n, m);

    return 0;
}