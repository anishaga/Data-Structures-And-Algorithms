#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void takeInput(int a[], int n)
{
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i=0;i<n;i++)
    {
        cout << a[i] <<" ";
    }
    cout << endl;
}

vector<int>* removeDuplicates(int a[], int n)
{
    unordered_map<int,bool> hasOccurred;
    vector<int>* final = new vector<int>();
    for (int i=0; i<n; i++)
    {
        if (hasOccurred.count(a[i]) == 0)
        {
            final->push_back(a[i]);
            hasOccurred[a[i]] = 1;
        }
    }
    return final;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int a[100];
    int n;
    cin >> n;

    takeInput(a, n);
    printArray(a,n);
    vector<int>* ans = removeDuplicates(a,n);
    for (int i=0; i<ans->size(); i++)
    {
        cout << ans->at(i)<<" ";
    }

    return 0;
}
