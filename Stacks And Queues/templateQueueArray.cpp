#include <bits/stdc++.h>
using namespace std;
template<typename T>

class QueueUsingArray
{
    T *data;
    int nextIndex;
    int firstIndex;
    int capacity;
    int size;

public:
    QueueUsingArray(int maxSize)
    {
        data = new T[maxSize];
        nextIndex = 0;
        firstIndex = -1;
        capacity = maxSize;
        size = 0;
    }

    void enqueue(T element)
    {
        if (size == capacity)
        {
            cout << "Queue Is Full" << endl;
            return;
        }
        else
        {
            data[nextIndex] = element;
            nextIndex = (nextIndex + 1) % capacity;
            size++;
            if (firstIndex == -1)
            {
                firstIndex++;
            }
        }
    }

    T dequeue()
    {
        if (size == 0)
        {
            cout << "Queue Is Empty " << endl;
            return INT_MIN;
        }
        else
        {
            T ans = data[firstIndex];
            firstIndex = (firstIndex + 1) % capacity;
            size--;
            return ans;
        }
    }

    T front()
    {
        if (size == 0)
        {
            cout << "Queue Is Empty " << endl;
            return INT_MIN;
        }
        else
        {
            return data[firstIndex];
        }
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    QueueUsingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;

    return 0;
}
