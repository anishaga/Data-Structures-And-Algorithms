#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> takeInput(int k)
{
    vector<vector<int>> v;

    while (k > 0)
    {
        int size;
        cin >> size;

        vector<int> temp;
        while (size > 0)
        {
            int num;
            cin >> num;
            temp.push_back(num);
            size--;
        }

        v.push_back(temp);
        k--;
    }

    return v;
}

vector<int> mergeKSortedArrays(vector<vector<int>> v, int k)
{
    vector<int> ans;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push({v[i][0], {i, 0}});
    }

    while (!pq.empty())
    {
        // Remove the minimum element from the heap.
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();

        // Add the removed element to the output array.
        ans.push_back(curr.first);

        // i is the array number and j is the index of the removed element in the ith array.
        int i = curr.second.first;
        int j = curr.second.second;

        // If the next element of the extracted element exists, add it to the heap.
        if (j + 1 < v[i].size())
        {
            pq.push({v[i][j + 1], {i, j + 1}});
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

    int k;
    cin >> k;
    vector<vector<int>> v = takeInput(k);

    vector<int> ans = mergeKSortedArrays(v, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}