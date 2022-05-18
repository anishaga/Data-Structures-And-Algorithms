#include <iostream>
using namespace std;

void isConnected(int **edges, int n, bool *visited, int sv)
{
    visited[sv] = 1;

    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            isConnected(edges, n, visited, i);
        }
    }
}

bool isConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    isConnected(edges, n, visited, 0);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            return 0;
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

    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];

    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << isConnected(edges, n);

    return 0;
}