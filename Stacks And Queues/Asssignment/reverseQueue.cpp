#include <bits/stdc++.h>
using namespace std;
#include <queue>

void reverseQueue(queue<int> &q)
{
  if (q.size() == 0)
  {
      return;
  }

  int temp = q.front();
  q.pop();
  reverseQueue(q);
  q.push(temp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int iterations;
    cin >> iterations;

    while (iterations > 0)
    {
        int n;
        cin >> n;
        int count = n;
        queue<int> q;
        
        while (count > 0)
        {
            int data;
            cin>>data;
            q.push(data);
            count--;
        }

        reverseQueue(q);

        count = n;
        while (count > 0)
        {
            cout << q.front() <<" ";
            q.pop();
            count--;
        }

        cout << endl;
        iterations--;
    }
    return 0;
}
