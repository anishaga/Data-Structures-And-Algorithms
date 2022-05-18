#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;
};

void takeInput(Edge *input, int e)
{
    for (int i = 0; i < e; i++)
    {
        int src, dest, wght;
        cin >> src >> dest >> wght;
        input[i].source = src;
        input[i].destination = dest;
        input[i].weight = wght;
    }
}

bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int *parent, int v)
{
    if (parent[v] == v)
    {
        return v;
    }

    return findParent(parent, parent[v]);
}

void kruskals(Edge *input, int n, int e)
{
    sort(input, input + e, cmp);
    Edge *output = new Edge[n - 1];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        Edge currentEdge = input[i];
        int p1 = findParent(parent, currentEdge.source);
        int p2 = findParent(parent, currentEdge.destination);

        if (p1 != p2)
        {
            output[count] = currentEdge;
            count++;
            parent[p1] = parent[p2];
        }
        i++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].destination)
        {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
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

    Edge *input = new Edge[e];
    takeInput(input, e);

    kruskals(input, n, e);

    return 0;
}