#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    Node<T> *next;
    T data;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    void push(T element)
    {
        Node<T> *n = new Node<T>(element);
        n->next = head;
        head = n;
        size++;
    }

    T pop()
    {
        if (head == NULL)
        {
            return -1;
        }
        T temp = head->data;
        head = head->next;
        size--;
        return temp;
    }

    T top()
    {
        if (head == NULL)
        {
            return -1;
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

    int num;
    cin >> num;

    Stack<int> s1;

    while (num != 0)
    {
        int n;
        cin >> n;

        if (n == 1)
        {
            int element;
            cin >> element;
            s1.push(element);
        }
        if (n == 2)
        {
            cout << s1.pop() << endl;
        }
        if (n == 3)
        {
            cout << s1.top() << endl;
        }
        if (n == 4)
        {
            cout << s1.getSize() << endl;
        }
        if (n == 5)
        {
            cout << s1.isEmpty() << endl;
        }
        num--;
    }
    return 0;
}
