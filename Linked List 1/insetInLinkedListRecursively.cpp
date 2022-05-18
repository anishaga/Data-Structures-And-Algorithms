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

Node *insertInLL(Node *head, int position, int element)
{
    if (head == NULL)
    {
        return head;
    }

    if (position == 0)
    {
        Node *n = new Node(element);
        n->next = head;
        return n;
    }

    // Node *temp = head;
    head->next = insertInLL(head->next, position - 1, element);
    //temp->next =dump;
    return head;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Node *head = takeInput();
    print(head);

    int position;
    cin >> position;

    int element;
    cin >> element;

    head = insertInLL(head, position, element);
    print(head);

    return 0;
}
