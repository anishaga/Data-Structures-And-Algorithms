#include <iostream>
using namespace std;

void island(int **edges, int n, int sv, bool *visited)
{
    visited[sv] = 1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && edges[sv][i] == 1)
        {
            island(edges, n, i, visited);
        }
    }
}

int island(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            island(edges, n, i, visited);
            count++;
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

    cout << island(edges, n);
    return 0;
}