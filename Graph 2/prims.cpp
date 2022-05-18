#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *weight, bool *visited, int n)
{
    int minVertex = -1;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edges, int n)
{
    bool *visited = new bool[n];
    int *parent = new int[n];
    int *weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        weight[i] = INT_MAX;
    }

    weight[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < n - 1; i++)
    {
        // Find Min Vertex
        int minVertex = findMinVertex(weight, visited, n);
        // Mark The Vertex As Visited
        visited[minVertex] = 1;
        // Explore Unvisited Neighbours
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (edges[minVertex][j] < weight[j])
                {
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
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
        int f, s, w;
        cin >> f >> s >> w;

        edges[f][s] = w;
        edges[s][f] = w;
    }

    prims(edges, n);

    return 0;
}