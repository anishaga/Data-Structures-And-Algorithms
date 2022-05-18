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

Node *evenAfterOdd(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *even = head;
    Node *odd = head;
    Node *evenPrev = NULL;

    while (even != NULL)
    {
        if (odd->data % 2 != 0)
        {
            evenPrev = even;
            odd = odd->next;
            even = even->next;
        }
        else
        {
            if (even->data % 2 != 0)
            {
                Node *n = new Node(odd->data);
                odd->data = even->data;
                n->next = odd->next;
                odd->next = n;

                evenPrev->next = even->next;
                odd = odd->next;
                even = even->next;
            }
            else
            {
                evenPrev = even;
                even = even->next;
            }
        }
    }
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

        head = evenAfterOdd(head);
        print(head);

        iterations--;
        cout << endl;
    }

    return 0;
}
