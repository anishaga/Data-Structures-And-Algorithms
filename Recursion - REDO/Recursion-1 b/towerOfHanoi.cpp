#include <iostream>
using namespace std;

void towerOfHanoi(int n, char start, char mid, char end)
{
    if (n == 0)
    {
        return;
    }

    if (n == 1)
    {
        cout << start << " " << end << endl;
        return;
    }

    if (n == 2)
    {
        cout << start << " " << mid << endl;
        cout << start << " " << end << endl;
        cout << mid << " " << end << endl;
        return;
    }

    towerOfHanoi(n - 1, start, end, mid);
    cout << start << " " << end << endl;
    towerOfHanoi(n - 1, mid, start, end);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    towerOfHanoi(n, 'a', 'b', 'c');

    return 0;
}