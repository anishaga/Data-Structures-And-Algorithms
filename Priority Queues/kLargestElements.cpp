#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> kLargestElements(int a[], int n, int k)
{
    int i = 0;
    priority_queue<int, vector<int>, greater<int>> temp;

    while (i < k)
    {
        temp.push(a[i]);
        i++;
    }

    while (i < n)
    {
        if (a[i] > temp.top())
        {
            temp.pop();
            temp.push(a[i]);
        }
        i++;
    }

    vector<int> ans;
    while (temp.size() != 0)
    {
        ans.push_back(temp.top());
        temp.pop();
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int *a = new int[n];
    takeInputArray(a, n);
    int k;
    cin >> k;

    vector<int> ans = kLargestElements(a, n, k);

    
    for (int i=0; i<ans.size() ; i++)
    {
        cout << ans[i] <<endl;
    }
    return 0;
}