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

    void insertElement(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[parentIndex] < pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;

                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int deleteElement()
    {
        if (pq.size() == 0)
        {
            cout << "Empty Queue Bro" << endl;
            return 0;
        }

        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = (2 * parentIndex) + 1;
        int rightChildIndex = (2 * parentIndex) + 2;

        while (leftChildIndex < pq.size())
        {
            int maxIndex = parentIndex;

            if (pq[maxIndex] < pq[leftChildIndex])
            {
                maxIndex = leftChildIndex;
            }

            if (rightChildIndex < pq.size() && pq[maxIndex] < pq[rightChildIndex])
            {
                maxIndex = rightChildIndex;
            }

            if (maxIndex == parentIndex)
            {
                break;
            }

            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = (2 * parentIndex) + 2;
        }
        return ans;
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMax()
    {
        return pq[0];
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    PriorityQueue p;

    p.insertElement(4);
    p.insertElement(10);
    p.insertElement(15);
    p.insertElement(17);
    p.insertElement(21);
    p.insertElement(67);
    p.insertElement(100);

    cout << p.getMax() << endl;
    cout << p.isEmpty() << endl;
    cout << p.getSize() << endl;

    while (!p.isEmpty())
    {
        cout << p.deleteElement() << " ";
    }
    cout << endl;

    return 0;
}