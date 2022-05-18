#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n<3)
    {
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    cout << fibonacci(n) << endl;
    return 0;
}