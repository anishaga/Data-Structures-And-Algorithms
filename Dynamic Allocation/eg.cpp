#include <iostream>
using namespace std;

void updateValue(int *p)
{
    *p = 610 % 255;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    char ch = 'A';
    updateValue((int *)&ch);
    cout << ch;
}