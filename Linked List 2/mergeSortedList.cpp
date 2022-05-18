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

Node *mergeSorted(Node *node1, Node *node2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (node1 != NULL && node2 != NULL)
    {
        if ((node1->data) > (node2->data))
        {
            Node *newNode = new Node(node2->data);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            node2 = node2->next;
        }
        else
        {
            Node *newNode = new Node(node1->data);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            node1 = node1->next;
        }
    }

    while (node1 != NULL)
    {
        Node *newNode = new Node(node1->data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        node1 = node1->next;
    }

    while (node2 != NULL)
    {
        Node *newNode = new Node(node2->data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        node2 = node2->next;
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
        Node *node1 = takeInput();
        print(node1);

        Node *node2 = takeInput();
        print(node2);

        Node *node3 = mergeSorted(node1, node2);
        print(node3);
        cout << endl;
        iterations--;
    }

    return 0;
}
