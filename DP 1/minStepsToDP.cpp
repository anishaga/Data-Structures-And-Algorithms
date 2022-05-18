#include <iostream>
using namespace std;

int minSteps(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 0;

    for (int i = 2; i < n + 1; i++)
    {
        int x = 1 + ans[i-1];
        if (i%2 == 0)
        {
            x = min(x,1+ans[i/2]);
        }

        if (i%3 == 0)
        {
            x= min(x,1+ans[i/3]);
        }
        ans[i] = x;
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

    cout << minSteps(n) << endl;

    return 0;
}