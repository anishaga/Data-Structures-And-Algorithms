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

vector<int> mergeKSorted(vector<vector<int>> v, int k)
{
    if (k == 1)
    {
        return v[0];
    }
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;

    int index = 0;

    while (1)
    {
        int i = 0;
        while (i < k)
        {
            if (v[i].size() - 1 < index)
            {
                // cout << "i: " << i << " "
                //      << "index: " << index << " "
                //      << "ans: " << v[i].size() << endl;

                i++;
                continue;
            }
            pq.push(v[i][index]);
            // cout << "i: " << i << " "
            //      << "index: " << index << " "
            //      << "ans: " << v[i][index] << endl;
            i++;
        }
        ans.push_back(pq.top());
        pq.pop();

        if (pq.size() == 0)
        {
            break;
        }
        index++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int iterations;
    cin >> iterations;

    int k;
    cin >> k;
    vector<vector<int>> v = takeInput(k);

    vector<int> ans = mergeKSorted(v, k);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}