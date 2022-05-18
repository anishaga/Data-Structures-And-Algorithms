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
    int index = 0, i = 0, j = mid+1;

    while (i <= mid && j <= end)
    {
        if (a[i] < a[j])
        {
            temp[index] = a[i];
            index++;
            i++;
        }
        else if (a[i] > a[j])
        {
            temp[index] = a[j];
            index++;
            j++;
        }
        else if (a[i] == a[j])
        {
            temp[index] = a[i];
            index++;
            temp[index] = a[j];
            index++;
            i++;
            j++;
        }
    }

    
    if (i > mid)
    {
        while (j<=end)
        {
        temp[index] = a[j];
        index++;
        j++;
        }
    }
    if (j > end)
    {
        while (i <= mid)
        {
        temp[index] = a[i];
        index++;
        i++;
        }
    }


    for (i = 0; i < size; i++)
    {
        a[i] = temp[i];
    }
    printArray(a, size);
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

    mergeArray(a,0,n-1);
    return 0;
}
