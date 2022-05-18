#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
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

void mergeArray(int a[], int si, int end)
{
    int mid = (si + end) / 2;
    int size = end - si + 1;
    int temp[size];
    int index = 0;
    int i = si;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            temp[index] = a[i];
            index++;
            i++;
        }
        else
        {
            temp[index] = a[j];
            index++;
            j++;
        }
    }

    while (j <= end)
    {
        temp[index] = a[j];
        index++;
        j++;
    }

    while (i <= mid)
    {
        temp[index] = a[i];
        index++;
        i++;
    }

    index = 0;
    for (i = si; i <= end; i++)
    {
        a[i] = temp[index];
        index++;
    }
}

void mergeSort(int a[], int si, int end)
{
    if (si >= end)
    {
        return;
    }

    int mid = (si + end) / 2;
    mergeSort(a, si, mid);
    mergeSort(a, mid + 1, end);
    mergeArray(a, si, end);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int a[100];
    int n;
    cin >> n;
    inputArray(a, n);
    mergeSort(a, 0, n - 1);
    printArray(a, n);

    return 0;
}
