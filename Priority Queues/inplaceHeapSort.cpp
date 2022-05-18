#include <iostream>
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

void inplaceHeapSort(int a[], int n)
{
    //Do Insertion Work First:

    int i = 1;

    while (i < n)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (a[parentIndex] > a[childIndex])
            {
                int temp = a[parentIndex];
                a[parentIndex] = a[childIndex];
                a[childIndex] = temp;

                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
        i++;
    }

    // Do Deletion Now

    int sizeOfHeap = n;
    while (sizeOfHeap > 0)
    {
        int temp = a[0];
        a[0] = a[sizeOfHeap-1];
        a[sizeOfHeap-1] = temp;

        sizeOfHeap--;

        int parentIndex = 0;
        int leftChildIndex = (2*parentIndex)+1;
        int rightChildIndex = (2*parentIndex)+2;

        while (leftChildIndex < sizeOfHeap)
        {
            int minIndex = parentIndex;

            if (a[minIndex] > a[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < sizeOfHeap && a[minIndex] > a[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if (minIndex == parentIndex)
            {
                break;
            }

            int temp = a[minIndex];
            a[minIndex] = a[parentIndex];
            a[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2*parentIndex)+1;
            rightChildIndex = (2*parentIndex)+2;
        }
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
    int *a = new int[n];

    takeInputArray(a, n);
    inplaceHeapSort(a, n);
    printArray(a,n);
    return 0;
}
