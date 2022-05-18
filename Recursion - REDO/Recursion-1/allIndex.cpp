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

// void allIndex(int a[], int n, int k,vector<int> &v,int index)
// {
//     if (n == 0)
//     {
//         return;
//     }

//     if (a[0] == k)
//     {
//         v.push_back(index);
//     }

//     allIndex(a+1,n-1,k,v,index+1);
// }

int allIndexes(int a[], int n, int k,int output[])
{
    if (n==0)
    {
        return 0;
    }
    int size = allIndexes(a,n-1,k,output);

    if (a[n-1] == k)
    {
        output[size] = n-1;
        size++;
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

    // vector<int> v;
    // allIndex(a,n,k,v,0);
    
    // for (int i=0; i<v.size(); i++)
    // {
    //     cout << v[i] <<" ";
    // }

    int *output = new int[n];

    int size = allIndexes(a,n,k,output);

    for (int i=0; i<size; i++)
    {
        cout << output[i] <<" ";
    }
    return 0;
}