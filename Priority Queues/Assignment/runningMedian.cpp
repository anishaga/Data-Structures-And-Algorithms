#include <iostream>
#include <queue>
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

void median(int a[], int n)
{
    if (n==0)
    {
        return;
    }
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int med = a[0];
    maxHeap.push(a[0]);
    cout << med << " ";

    int i = 1;
    while (i < n)
    {
        int x = a[i];

        if (maxHeap.size() > minHeap.size())
        {
            if (x < med)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(x);
            }
            else
            {
                minHeap.push(x);
            }

            med = (minHeap.top() + maxHeap.top()) / 2;
        }
        else if (maxHeap.size() == minHeap.size())
        {
            if (x < med)
            {
                maxHeap.push(x);
                med = maxHeap.top();
            }
            else
            {
                minHeap.push(x);
                med = minHeap.top();
            }
        }
        else
        {
            if (x > med)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);
            }
            else
            {
                maxHeap.push(x);
            }
            med = (minHeap.top() + maxHeap.top()) / 2;
        }

        cout << med << " ";

        i++;
    }
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
    median(a, n);

    return 0;
}