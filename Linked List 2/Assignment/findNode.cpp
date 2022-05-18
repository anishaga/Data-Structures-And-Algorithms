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

void findNode(Node *head, int element, int position)
{
    if (head == NULL)
    {
        cout<<-1;
        return;
    }

    if (head->data == element)
    {
        cout << position;
        return;
    }

    findNode(head->next, element, position + 1);
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

        int element;
        cin >> element;

        findNode(head, element, 0);

        iterations--;
        cout << endl;
    }
    return 0;
}
