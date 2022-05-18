#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int maxFrequency(int a[], int n)
{
    unordered_map<int, int> freq;
    vector<int> helper;

    for (int i = 0; i < n; i++)
    {
        if (freq.count(a[i]) == 0)
        {
            freq[a[i]] = 1;
            helper.push_back(a[i]);
        }
        else
        {
            freq[a[i]] = freq[a[i]] + 1;
        }
    }
    int max = freq[helper[0]];
    int num = helper[0];

    for (int i = 1; i < helper.size(); i++)
    {
        if (freq[helper[i]] > max)
        {
            max = freq[helper[i]];
            num = helper[i];
        }
    }

    return num;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int a[100];
    takeInputArray(a, n);

    cout << maxFrequency(a, n);

    return 0;
}
