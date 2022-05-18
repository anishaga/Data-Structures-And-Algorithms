#include <iostream>
#include <unordered_map>
using namespace std;

void takeInputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int longestSubArray(int a[], int n)
{
    unordered_map<int,int> ourMap;
    int sum = 0;
    int maxLen = 0;
    for (int i=0; i<n; i++)
    {
        sum = sum + a[i];
        if (ourMap.count(sum) == 1)
        {
            int len = 1 +  i - (ourMap[sum]+1);
            if (len > maxLen)
            {
                maxLen = len;
            }
        }
        ourMap[sum] = i;
    }
    return maxLen;
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

    cout << longestSubArray(a,n) << endl;

    return 0;
}