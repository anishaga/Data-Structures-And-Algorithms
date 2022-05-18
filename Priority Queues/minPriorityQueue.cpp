#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (pq.size() != 0)
        {
            return pq[0];
        }
        else
        {
            return 0; //Priority Queue Is Empty
        }
    }

    void insertElement(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[parentIndex] > pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int deleteElement()
    {
        if (pq.size() == 0)
        {
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int rightChildIndex = 2 * parentIndex + 2;
        int leftChildIndex = 2 * parentIndex + 1;

        while (leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            rightChildIndex = 2 * parentIndex + 2;
            leftChildIndex = 2 * parentIndex + 1;
        }
        return ans;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    PriorityQueue p;

    p.insertElement(100);
    p.insertElement(10);
    p.insertElement(15);
    p.insertElement(4);
    p.insertElement(17);
    p.insertElement(21);
    p.insertElement(67);

    cout << p.getMin() << endl;
    cout << p.isEmpty() << endl;
    cout << p.getSize() << endl;

    while (!p.isEmpty())
    {
        cout << p.deleteElement() << " ";
    }
    cout << endl;

    return 0;
}