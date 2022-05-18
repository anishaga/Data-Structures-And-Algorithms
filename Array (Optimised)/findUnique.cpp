#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int findUnique(int a[], int n)
{
    int i,j;
    for (j = 0; j < n; j++)
    {
        int temp = a[j];
        int count = 0;

        for (i = 0; i < n; i++)
        {
            if (a[i] == temp)
            {
                count ++;
            }
        }

        if (count == 1)
        {
            return temp;
        }
    }

    return -1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int iterations;
    cin >> iterations;

    while (iterations > 0 )
    {
    int n;
    cin >> n;

    int a[100];

    inputArray(a, n);
    cout << findUnique(a, n);

    cout<<endl;
    iterations --;
    }

    return 0;
}
