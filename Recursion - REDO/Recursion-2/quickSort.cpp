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
    cout << endl;
}

int partition(int a[], int si, int end)
{
    int count = 0;
    int num = a[si];
    for (int i = si + 1; i <= end; i++)
    {
        if (a[i] < num)
        {
            count++;
        }
    }

    a[si] = a[si + count];
    a[si + count] = num;
    int i = si;
    int j = end;

    while (i < si + count )
    {
        if (a[i] < num)
        {
            i++;
        }
        else if (a[j] > num)
        {
            j--;
        }
        else if (a[i] > num && a[j] < num)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }

    return si + count;
}

void quickSort(int a[], int si, int end)
{
    if (si >= end)
    {
        return;
    }

    int p = partition(a, si, end);
    quickSort(a, si, p - 1);
    quickSort(a, p + 1, end);
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
    quickSort(a, 0, n - 1);
    printArray(a, n);

    return 0;
}