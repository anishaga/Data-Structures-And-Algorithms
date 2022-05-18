#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}


void pSubSet(int a[], int n, int op[], int m)
{
    if (n == 0)
    {
        for (int i = 0; i < m; i++)
        {
            cout << op[i] << " ";
        }
        cout << endl;
        return;
    }

    int newout[m + 1];
    int i;
    for (i = 0; i < m; i++)
    {
        newout[i] = op[i];
    }

    newout[i] = a[0];
    pSubSet(a + 1, n - 1, newout, m + 1);
    pSubSet(a + 1, n - 1, op, m);
}

void sub(int a[], int n)
{
    int op[100];
    pSubSet(a, n, op, 0);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int a[100];

    inputArray(a, n);

    sub(a, n);


    return 0;
}



