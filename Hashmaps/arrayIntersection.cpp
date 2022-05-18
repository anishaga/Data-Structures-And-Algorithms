#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printIntersection(int a[], int n1, int b[], int n2)
{
    unordered_map<int, bool> intersection;

    for (int i = 0; i < n1; i++)
    {
        intersection[a[i]] = 0;
    }

    for (int i = 0; i < n2; i++)
    {
        if (intersection.count(b[i]) == 1)
        {
            intersection[b[i]] = 1;
        }
    }

    for (int i=0 ; i<n1; i++)
    {
        if (intersection[a[i]] == 1)
        {
            cout << a[i] <<" ";
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int iterations;
    cin >> iterations;

    while (iterations > 0)
    {
        int n1;
        cin >> n1;
        int a[100];
        takeInputArray(a, n1);

        int n2;
        cin >> n2;
        int b[100];
        takeInputArray(b, n2);

        printIntersection(a, n1, b, n2);

        iterations--;
        cout << endl;
    }

    return 0;
}