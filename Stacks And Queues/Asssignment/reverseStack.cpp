#include <bits/stdc++.h>
using namespace std;
#include <stack>

void reverseStack(stack<int> &s1, stack<int> &s2)
{
    if (s1.size() == 0)
    {
        return;
    }

    int temp = s1.top();
    s1.pop();

    reverseStack(s1, s2);
    while (s1.size() != 0)
    {
        int dump = s1.top();
        s1.pop();
        s2.push(dump);
    }
    s1.push(temp);

    while (s2.size() != 0)
    {
        int dump = s2.top();
        s2.pop();
        s1.push(dump);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    stack<int> s1;
    stack<int> s2;

    int count = n;
    while (count > 0)
    {
        int data;
        cin >> data;
        s1.push(data);
        count--;
    }

    reverseStack(s1, s2);
    count = n;
    while (count > 0)
    {
        cout<<s1.top()<<" ";
        s1.pop();
        count--;
    }

    return 0;
}
