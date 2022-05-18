#include <iostream>
using namespace std;

void printNumber(int n)
{
    if (n==1)
    {
        cout << 1 <<" ";
        return;
    }

    printNumber(n-1);
    cout << n << " ";
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    printNumber(n);

    return 0;
}