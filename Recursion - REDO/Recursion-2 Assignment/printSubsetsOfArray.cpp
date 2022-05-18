#include <iostream>
#include <vector>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printSubsets(int a[], int n, int output[], int m)
{
    if (n == 0)
    {
        for (int i = 0; i < m; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }

    int newout[m + 1];
    int i;
    for (i = 0; i < m; i++)
    {
        newout[i] = output[i];
    }

    newout[i] = a[0];
    printSubsets(a + 1, n - 1, output, m);
    printSubsets(a + 1, n - 1, newout, m + 1);

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
    int output[100];

    printSubsets(a, n, output, 0);

    return 0;
}