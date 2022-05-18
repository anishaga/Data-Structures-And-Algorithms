#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    if (1 & n)
    {
        cout << "Odd" << endl;
    }
    else
    {
        cout << "Even " << endl;
    }


    return 0;
}