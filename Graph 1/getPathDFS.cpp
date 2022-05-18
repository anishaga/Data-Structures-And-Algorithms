#include <iostream>
#include <vector>
using namespace std;

vector<int> getPath(int **edges, int n, int sv, int ev, bool *visited)
{
    visited[sv] = 1;

    if (sv == ev)
    {
        vector<int> temp;
        temp.push_back(ev);
        return temp;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {

        if (edges[sv][i] == 1)
        {
            if (!visited[i])
            {
                ans = getPath(edges, n, i, ev, visited);

                if (ans.size() != 0)
                {
                    ans.push_back(sv);
                    return ans;
                }
            }
        }
    }
    return ans;
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
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    vector<int> path = getPath(edges, n, a, b, visited);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << endl;
    }

    return 0;
}