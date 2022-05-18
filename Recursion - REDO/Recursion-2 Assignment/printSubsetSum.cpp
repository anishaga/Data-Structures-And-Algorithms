#include <iostream>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printSubsetSum(int a[], int n, int k, int *output, int size)
{
    if (n == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < size; i++)
            {
                cout << output[i] <<" ";
            }
            cout <<endl;
        }
        return;
    }

    int newout[size + 1];
    int i;
    for (i = 0; i < size; i++)
    {
        newout[i] = output[i];
    }

    newout[i] = a[0];

    printSubsetSum(a+1,n-1,k,output,size);

    printSubsetSum(a+1,n-1,k-a[0],newout,size+1);

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

    int *output = new int[n];

    printSubsetSum(a, n, k, output, 0);

    return 0;
}