#include <iostream>
using namespace std;

void takeInputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
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

    int XOR = 0;

    // Finding XOR Of All Numbers Of Array
    for (int i = 0; i < n; i++)
    {
        XOR = XOR ^ a[i];
    }

    // Now Finding The Position Of 1st Set Bit From Right
    int count = 0;
    while (XOR != 0)
    {
        if (XOR & 1)
        {
            break;
        }
        count++;
        XOR = XOR >> 1;
    }

    // Now Seggregating Them

    int XOR1 = 0;
    int XOR2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] & (1 << count))
        {
            XOR1 = XOR1 ^ a[i];
        }
        else
        {
            XOR2 = XOR2 ^ a[i];
        }
    }

    cout << XOR1 << endl;
    cout << XOR2 << endl;

    return 0;
}