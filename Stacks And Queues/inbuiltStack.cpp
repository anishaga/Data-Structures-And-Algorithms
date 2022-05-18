#include <iostream>
using namespace std;
#include <stack>

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    stack<int> s;

    s.push(10);
    cout << s.top() << endl;
    cout << s.size() << endl;
    s.pop();
    s.pop();
    cout << s.empty() << endl;

    return 0;
}
