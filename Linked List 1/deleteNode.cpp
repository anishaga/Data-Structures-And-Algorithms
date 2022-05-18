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

Node *deleteNode(Node *head, int index)
{
    Node *temp1 = head;
    Node *temp2 = NULL;
    Node *temp3 = NULL;

    if (index == 0)
    {
        head = head->next;
        return head;
    }

    while (index != 0)
    {
        temp2 = temp1;
        temp1 = temp1->next;
        if (temp1== NULL)
        {
            return head;
        }
        temp3 = temp1->next;
        index--;
    }

    temp2->next = temp3;
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

    int index;
    cin >> index;

    head = deleteNode(head, index);
    print(head);

    return 0;
}
