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
        this->next = NULL;
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

Node *insertAt(Node *head, int position, int element)
{
    Node *temp1 = head;
    Node *temp2 = NULL;
    if (position == 0)
    {
        Node *n = new Node(element);
        head = n;
        n->next = temp1;
        return head;
    }
    else
    {
        while (position != 0)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            position--;
            if (temp1 == NULL)
            {
                return head;
            }
        }

        Node *n = new Node(element);
        temp2->next = n;
        n->next = temp1;

        return head;
    }
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

    Node *temp = insertAt(head, position, element);
    print(temp);

    return 0;
}
