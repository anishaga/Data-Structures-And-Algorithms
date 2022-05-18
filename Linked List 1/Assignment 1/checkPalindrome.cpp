#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1)
    {
        Node *n = new Node(data);
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
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverseList(Node *head, int size)
{
    Node *newNode = NULL;
    Node *tail = NULL;

    // cout << size << endl;
    // cout << head->data << endl;
    while (size > 0)
    {
        Node *temp = head;
        int len = size;

        while (len > 1)
        {
            temp = temp->next;
            len--;
        }

        if (newNode == NULL)
        {
            newNode = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size--;
    }
    tail->next = NULL;
    return newNode;
}

bool checkPalindrome(Node *head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        return 0;
    }
    int len = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    int size = len / 2;

    temp = head;
    while (size != 0)
    {
        temp = temp->next;
        size--;
    }
    size = len / 2;
    Node *dump;
    if (len % 2 == 0)
    {
        dump = temp;
    }
    else
    {
        dump = temp->next;
    }
    dump = reverseList(dump, size);
    // print(dump);

    while (size != 0)
    {
        if (dump->data != head->data)
        {
            return 0;
        }
        dump = dump->next;
        head = head->next;
        size--;
    }

    return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int iterations;
    cin >> iterations;
    while (iterations > 0)
    {
        Node *head = takeInput();
        // print(head);
        cout << checkPalindrome(head);

        iterations--;
        cout << endl;
    }

    return 0;
}
