#include <iostream>
#include <queue>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << a[i]<<" ";
    }
    cout << endl;
}

bool checkMaxHeap(int a[], int n)
{

    int i=0;
    while (i < n)
    {
        int parentIndex = i;
        int leftChildIndex = (parentIndex*2) + 1;
        int rightChildIndex = (parentIndex*2) + 2;

        if (leftChildIndex < n && a[parentIndex] < a[leftChildIndex] )
        {
            return 0;
        }
        if (rightChildIndex < n && a[parentIndex] < a[rightChildIndex])
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int* a = new int[n];
    takeInputArray(a,n);
    cout << checkMaxHeap(a,n) << endl;

    return 0;
}