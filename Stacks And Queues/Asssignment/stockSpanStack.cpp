#include <bits/stdc++.h>
using namespace std;
#include <stack>

void takeInput(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    int *a = new int[n];
    takeInput(a, n);

    int *b = new int[n];

    stack<int> s;
    s.push(0);
    b[0] = 1;
    for (int i = 1; i < n; i++)
    {        
        while (s.size() != 0 && a[i] > a[s.top()])
        {
            s.pop();
        }

        if (s.size() != 0)
        {
            b[i] = i - s.top();
        }
        else
        {
            b[i] = i + 1;
        }

        s.push(i);
    }

printArray(b, n);

return 0;
}

// for (int i = 0; i < n; i++)
//     {
//         if (s.size() == 0)
//         {
//             s.push(a[i]);
//             b[i] = 1;
//         }
//         else
//         {
//             if (s.top() > a[i])
//             {
//                 b[i] = 1;
//                 while (s.size() != 0)
//                 {
//                     s.pop();
//                 }
//                 s.push(a[i]);
//             }
//             else
//             {
//                 s.push(a[i]);
//                 b[i] = s.size();
//             }
//         }
//     }