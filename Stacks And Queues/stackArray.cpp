#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int* data;
    int capacity;
    int nextIndex;

    public:
    Stack(int totalSize)
    {
        data= new int[totalSize];
        capacity = totalSize;
        nextIndex = 0;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout<<"Stack Is Full Bruh!"<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop()
    {
        if (nextIndex == 0)
        {
            cout<<"Stack Is Empty Bruh"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top()
    {
        if (nextIndex == 0)
        {
            cout<<"Stack Is Empty Bruh"<<endl;
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

    Stack s1(5);
    cout<<s1.isEmpty()<<endl;
    cout<<s1.size()<<endl;
    cout<<s1.top()<<endl;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(10);

    cout<<s1.size()<<endl;
    cout<<s1.isEmpty()<<endl;
    cout<<s1.top()<<endl;

    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;

    return 0;
}

