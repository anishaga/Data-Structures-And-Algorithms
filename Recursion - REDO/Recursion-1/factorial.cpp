#include <iostream>
using namespace std;

int factorial (int n)
{
    if (n<=1) 
    {
        return 1;
    }

    return factorial(n-1)*n;
}
int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout <<factorial(n) <<endl;

    return 0;
}