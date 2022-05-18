#include <bits/stdc++.h>
using namespace std;
template <typename T>

class Stack
{
    T *data;
    int capacity;
    int nextIndex;

    public:

    Stack()
    {
        capacity = 4;
        data = new T[capacity];
        nextIndex = 0;
    }

    void push(T element)
    {
        if (capacity == nextIndex)
        {
            T *newData = new T[capacity*2];
            for (int i=0; i<nextIndex; i++)
            {
                newData[i] = data[i];
            }
            delete []data;
            data = newData;
            capacity = capacity*2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T pop ()
    {
        if (nextIndex ==0)
        {
            cout<<"Stack Is Empty"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (nextIndex ==0)
        {
            cout<<"Stack Is Empty"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Stack<int> s1;
    cout<<s1.pop()<<endl;
    cout<<s1.isEmpty()<<endl;
    s1.push(69);
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    

    return 0;
}

