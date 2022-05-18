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
            cout << "Stack Is Empty" << endl;
            return 0;
        }
        T temp = head->data;
        Node<T>* a = head;
        head = head->next;
        size--;
        delete a;
        return temp;
    }

    T top()
    {
        if (head == NULL)
        {
            cout << "Stack Is Empty" << endl;
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

    Stack<char> s1;
    cout << s1.getSize() << endl;
    cout << s1.isEmpty() << endl;
    s1.push('a');
    s1.push('b');
    s1.push('c');
    cout << s1.top() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    cout << s1.getSize() << endl;

    return 0;
}
