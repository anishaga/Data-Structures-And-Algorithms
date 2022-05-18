#include <bits/stdc++.h>
using namespace std;

float geometricSum(int k)
{
    if (k==0)
    {
        return 1;
    }
    float temp = geometricSum(k-1);
    float dump = 1.0/(pow(2,k)) + temp;
    return dump;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    float k;
    cin>>k;

    cout<<geometricSum(k);

    return 0;
}
