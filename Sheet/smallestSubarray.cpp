#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int smallestSub(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    map[nums[0]] = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        nums[i] = nums[i] + nums[i - 1];
        map[nums[i]] = i;
    }

    int len = INT_MAX;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < k)
        {
            continue;
        }
        else  
        {
            int x = nums[i] - k;
            if (x == 0)
            {
                len = min(len, i);
            }
            if (map.count(x) != 0)
            {
                len = min(len, i - map[x]);
            }
        }
    }
    return len;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    int k;
    cin >> k;
    cout << smallestSub(nums, k);

    return 0;
}
