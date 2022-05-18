#include <bits/stdc++.h>
using namespace std;

void inputArray(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

int findDuplicate(int a[], int n)
{
    int i,j;
    for (i=0;i<n-1;i++)
    {
        int temp = a[i];
        for (j=i+1; j<n; j++)
        {
            if (a[j] == temp)
            {
                return temp;
            }
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

    while (iterations > 0)
    {
        int n;
        cin>>n;

        int a[100];

        inputArray(a,n);

        cout << findDuplicate(a,n);

        cout<<endl;
        iterations--;
    }


    return 0;
}
