#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> getPath(int **edges, int n, int sv, int ev)
{
    vector<int> ans;
    if (sv == ev)
    {
        return ans;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    unordered_map<int, int> myMap;
    queue<int> q;
    q.push(sv);
    visited[sv] = 1;
    int flag = 0;

    while (q.size() != 0)
    {
        if (flag == 1)
        {
            break;
        }
        int temp = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
            if (edges[temp][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                myMap[i] = temp;
                visited[i] = 1;
                if (i == ev)
                {
                    flag = 1;
                    break;
                }
            }
        }
    }

    if (flag == 0)
    {
        return ans;
    }

    int temp = ev;

    while (1)
    {
        ans.push_back(temp);

        if (myMap[temp] == sv)
        {
            ans.push_back(sv);
            break;
        }
        temp = myMap[temp];
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

    int sv, ev;
    cin >> sv >> ev;

    vector<int> path = getPath(edges, n, sv, ev);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << " ";
    }

    return 0;
}