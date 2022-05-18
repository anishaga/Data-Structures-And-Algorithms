#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:
    Queue()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    void enqueue(T element)
    {
        Node<T> *n = new Node<T>(element);

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    T dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue Is Empty";
            return 0;
        }
        T temp = head->data;
        Node<T> *dump = head;
        head = head->next;
        delete dump;
        size--;
        return temp;
    }

    T front()
    {
        if (head == NULL)
        {
            cout << "Queue Is Empty";
            return 0;
        }
        return head->data;
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

    Queue<int> q;
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
