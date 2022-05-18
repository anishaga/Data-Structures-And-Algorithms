#include <bits/stdc++.h>
using namespace std;

void takeInput(int a[], int n)
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int *a = new int[n];
    takeInput(a, n);

    int *b = new int[n];

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i-1; j >= 0; j--)
        {
            if (a[i] > a[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        b[i] = count;
    }

    printArray(b,n);

    return 0;
}
