#include <iostream>
using namespace std;

int multiplication(int m ,int n)
{
    if (n==0 || m==0)
    {
        return 0;
    }
    
    return m + multiplication(m,n-1);
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int m;
    cin >> m;

    int n;
    cin >> n;

    cout <<multiplication(m,n) << endl;

    return 0;
}