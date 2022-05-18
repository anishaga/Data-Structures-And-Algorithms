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

int partition(int a[], int si, int ei)
{
    int count_small = 0;
    int temp = a[si];
    for (int i = si; i <= ei; i++)
    {
        if (a[i] < temp)
        {
            count_small++;
        }
    }

    a[si] = a[si + count_small];
    a[si + count_small] = temp;
    temp = count_small;

    int i = si + count_small;
    while (si < i && ei > i)
    {
        if (a[si] >= a[i] && a[ei] < a[i])
        {
            int dump = a[si];
            a[si] = a[ei];
            a[ei] = dump;
            si++;
            ei--;
        }
        else if (a[si] < a[i] )
        {
            si++;
        }
        else if (a[ei] >= a[i] )
        {
            ei--;
        }
    }
    return si+count_small;
}

void quickSort(int a[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int c = partition(a, si, ei);
    cout<<c<<endl;
    quickSort(a, si, c - 1);
    quickSort(a, c + 1, ei);
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
    quickSort(a, 0, n - 1);
   printArray(a, n);
    return 0;
}
