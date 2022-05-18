#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int subset(int a[], int n, int output[][10])
{
    if (n <= 0)
    {
        output[0][0] = 0;
        return 1;
    }

    int size = subset(a + 1, n - 1, output);
    
    for (int i = 0; i < size; i++)
    {
        int len = output[i][0] + 1;
        output[i + size][0] = len;
        output[i + size][1] = a[0];
        for (int j = 2; j < len + 1; j++)
        {
            output[i + size][j] = output[i][j - 1];
        }
    }

    return 2 * size;
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

    int output[100][10];
    int size = subset(a, n, output);

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