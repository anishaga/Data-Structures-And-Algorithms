#include <iostream>
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
}

void mergeSortedArray(int *a, int si, int mid, int end)
{
    int i = si;
    int j = mid + 1;
    int *temp = new int[end - si + 1];
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    k = 0;
    for (int i = si; i <= end; i++)
    {
        a[i] = temp[k];
        k++;
    }
}

void mergeSort(int *a, int si, int end)
{
    if (si >= end)
    {
        return;
    }

    int mid = (si + end) / 2;

    mergeSort(a, si, mid);
    mergeSort(a, mid + 1, end);
    mergeSortedArray(a, si, mid, end);
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

    mergeSort(a, 0, n - 1);

    printArray(a, n);
    return 0;
}