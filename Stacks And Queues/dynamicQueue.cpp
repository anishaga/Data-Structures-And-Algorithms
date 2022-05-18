#include <bits/stdc++.h>
using namespace std;

class QueueUsingArray
{
    int *data;
    int nextIndex;
    int firstIndex;
    int capacity;
    int size;

public:
    QueueUsingArray()
    {
        data = new int[4];
        nextIndex = 0;
        firstIndex = -1;
        capacity = 4;
        size = 0;
    }

    void enqueue(int element)
    {
        if (size == capacity)
        {
           int* newData = new int[capacity*2];
           int j=0;
        for (int i=firstIndex; i<size; i++)
        {
            newData[j] = data[i];
            j++;
        }

        for (int i=0; i<firstIndex; i++)
        {
            newData[j] = data[i];
            j++;
        }
        delete []data;
        data = newData;
        firstIndex = 0;
        nextIndex = size;
        capacity = capacity*2;
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

    int dequeue()
    {
        if (size == 0)
        {
            cout << "Queue Is Empty " << endl;
            return INT_MIN;
        }
        else
        {
            int ans = data[firstIndex];
            firstIndex = (firstIndex + 1) % capacity;
            size--;
            return ans;
        }
    }

    int front()
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

    QueueUsingArray q;
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
