#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout << a[i]<<" ";
    }
    cout << endl;
}

int kLargestElement(int a[], int n, int k)
{
    priority_queue<int,vector<int>,greater<int>> temp;
    
    int i=0;
    while (i<k)
    {
        temp.push(a[i]);
        i++;
    }

    while (i < n)
    {
        if (a[i] > temp.top())
        {
            temp.pop();
            temp.push(a[i]);
        }
        i++;
    }
    return temp.top();
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int* a = new int[n];
    takeInputArray(a,n);
    int k;
    cin >> k;

    cout << kLargestElement(a,n,k) << endl;


    return 0;
}