#include <iostream>
#include <cmath>
using namespace std;

int numberOfBT(int h)
{
    int* ans = new int[h+1];
    int mod = pow(10,9) + 7;

    ans[0] = 1;
    ans[1] = 1;

    for (int i=2; i<h+1 ; i++)
    {
        int x = ans[i-1];
        int y = ans[i-2];

        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)((2*(long)(x)*y)%mod);

        ans[i] = (temp1+temp2)%mod; 
    }
    return ans[h];
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int h;
    cin >> h;

    cout << numberOfBT(h);


    return 0;
}