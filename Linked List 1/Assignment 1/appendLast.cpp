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

Node *appendLast(Node *head, int position)
{
    Node *temp = head;
    Node *dump = head;
    Node *temp1;

    while (position != 0)
    {
        temp1 = temp;
        temp = temp->next;
        position--;

        if (temp == NULL)
        {
            return head;
        }
    }
    head = temp;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = dump;
    temp1->next = NULL;

    return head;
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
        print(head);

        int position;
        cin >> position;

        head = appendLast(head, position-1);
        print(head);

        iterations--;
        cout << endl;
    }
    return 0;
}
