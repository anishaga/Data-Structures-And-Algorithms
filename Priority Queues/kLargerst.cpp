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

void sortKLargest(int a[], int n, int k)
{
    priority_queue<int> temp;
    int i = 0;
    while (i < k)
    {
        temp.push(a[i]);
        i++;
    }

    int index = 0;
    while (index < n)
    {
        a[index] = temp.top();
        temp.pop();
        if (k < n)
        {
            temp.push(a[k]);
            k++;
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

    int n;
    cin >> n;
    int *a = new int[n];
    takeInputArray(a, n);
    int k;
    cin >> k;

    sortKLargest(a, n, k);
    printArray(a,n);

    return 0;
}