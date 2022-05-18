#include <iostream>
#include <queue>
using namespace std;

void printGraphBFS(int **edges, int n, int sv)
{
    queue<int> q;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    q.push(sv);
    visited[sv] = 1;

    while (q.size() != 0)
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";

        for (int i = 0; i < n; i++)
        {
            if (edges[temp][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
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

    printGraphBFS(edges, n, 0);

    return 0;
}