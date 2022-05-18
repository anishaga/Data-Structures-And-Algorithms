#include <iostream>
#include <queue>
using namespace std;

void takeInputArray(int a[], int n)
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

int timeTaken(int a[], int n, int k)
{
    priority_queue<int> pq;
    queue<int> q;
    int time = 0;
    int i = 0;
    while (i < n)
    {
        pq.push(a[i]);
        q.push(i);
        i++;
    }
   
    while (pq.size()!= 0)
    {
        if (a[q.front()] == pq.top())
        {
            pq.pop();
            time++;
            if (q.front() == k)
            {
                return time;
            }
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    for (int i = 0; i<n; i++)
    {
        cout << q.front() << ": "<<pq.top()<<endl;
        q.pop();
        pq.pop();
    }

    // cout << pq.size() << endl;
    return -1;
}

int main()  
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int* a = new int[n];
    takeInputArray(a,n);

    int k;
    cin >> k;

    cout << timeTaken(a,n,k);

    return 0;
}