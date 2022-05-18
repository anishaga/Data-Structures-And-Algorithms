#include <iostream>
#include <queue>
using namespace std;

bool hasPath(int **edges, int n, int a, int b)
{
    if (a == b)
    {
        return 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    queue<int> q;
    q.push(a);
    visited[a] = 1;
    while (q.size() != 0)
    {
        int temp = q.front();
        q.pop();

        if (temp == b)
        {
            return 1;
        }

        for (int i = 0; i < n; i++)
        {
            if (edges[temp][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
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

    int a, b;
    cin >> a >> b;

    cout << hasPath(edges, n, a, b) << endl;
    return 0;
}