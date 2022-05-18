#include <iostream>
using namespace std;

int cycle(int **edges, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (edges[j][k] == 1 && k != i)
                    {
                        if (edges[i][k] == 1)
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count / 6;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << cycle(edges, n) << endl;

    return 0;
}