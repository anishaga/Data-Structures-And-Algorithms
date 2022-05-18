#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(bool *visited, int *distance, int n)
{
    int minVertex = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstras(int **edges, int n)
{
    bool *visited = new bool[n];
    int *distance = new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        distance[i] = INT_MAX;
    }

    distance[0] = 0;

    for (int i = 0; i < n - 1; i++ )
    {
        int minVertex = findMinVertex(visited, distance, n);
        visited[minVertex] = 1;

        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (distance[minVertex] + edges[minVertex][j] < distance[j])
                {
                    distance[j] = distance[minVertex] + edges[minVertex][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
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
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }

    dijkstras(edges, n);
    return 0;
}