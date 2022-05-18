#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int subsetSum(int a[], int n, int k, int output[][50])
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int s1 = subsetSum(a + 1, n - 1, k, output);
    int s2 = subsetSum(a + 1, n - 1, k - a[0], output + s1);

    int size = s1 + s2;
    for (int i = s1; i < size; i++)
    {
        for (int j = output[i][0]; j > 0; j--)
        {
            output[i][j + 1] = output[i][j];
        }
        output[i][1] = a[0];
        output[i][0]++;
    }
    return size;

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

    int k;
    cin >> k;

    int output[20][50];

    int size = subsetSum(a, n, k, output);

    for (int i = 0; i < size; i++)
    {
        int len = output[i][0];

        for (int j = 1; j <= len; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}