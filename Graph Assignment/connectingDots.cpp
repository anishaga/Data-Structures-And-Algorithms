#include <iostream>
using namespace std;

bool connectingDots(char **board, int n, int m, int i, int j, char c, bool **visited)
{
    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != c)
    {
        return 0;
    }

    if (visited[i][j])
    {
        return 1;
    }

    visited[i][j] = 1;
    board[i][j] = '.';

    bool ans = connectingDots(board, n, m, i - 1, j, c, visited);
    ans = ans || connectingDots(board, n, m, i, j - 1, c, visited);
    ans = ans || connectingDots(board, n, m, i, j + 1, c, visited);
    ans = ans || connectingDots(board, n, m, i + 1, j, c, visited);

    board[i][j] = c;

    return ans;
}

bool connectingDots(char **board, int n, int m)
{
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
            if (!visited[i][j])
            {
                if (connectingDots(board, n, m, i, j, board[i][j], visited))
                {
                    return 1;
                }
            }
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

    int n, m;
    cin >> n >> m;

    char **board = new char *[n];

    for (int i = 0; i < n; i++)
    {
        board[i] = new char[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << connectingDots(board, n, m);
    return 0;
}