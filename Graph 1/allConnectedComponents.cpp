#include <iostream>
#include <vector>
using namespace std;

void allConnected(int **edges, int n, bool *visited, int sv, vector<int> &ans)
{
    visited[sv] = 1;
    ans.push_back(sv);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && edges[sv][i] == 1)
        {
            allConnected(edges, n, visited, i, ans);
        }
    }
}

vector<vector<int>> allConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            vector<int> temp;
            allConnected(edges, n, visited, i, temp);
            // cout << temp.size() << endl;
            ans.push_back(temp);
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
        int f,s;
        cin >> f >> s;

        edges[s][f] = 1;
        edges[f][s] = 1;
    }

    vector<vector<int>> ans = allConnected(edges, n);
    // cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}