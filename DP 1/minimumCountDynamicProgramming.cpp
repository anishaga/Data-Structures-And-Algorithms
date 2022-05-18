#include <iostream>
#include <cmath>
using namespace std;

int minimumCount(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        int minimum = INT_MAX;
    
        for (int j = 1; j <=sqrt(i) ; j++)
        {
            int rem = i- j*j;

            if (ans[rem] < minimum)
            {
                minimum = ans[rem];
            }
        }
        ans[i] = minimum +1;
    } 
    return ans[n];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << minimumCount(n) << endl;
    return 0;
}