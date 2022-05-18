#include <bits/stdc++.h>
using namespace std;
#include <queue>
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    queue<int> q;

    q.push(69);
    cout << q.front() << endl;
    cout << q.size() << endl;
    q.pop();
    cout << q.front() << endl;

    cout << q.empty() << endl;


    return 0;
}
