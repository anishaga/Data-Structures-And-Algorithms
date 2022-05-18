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

void swapNode(Node *p1, Node *n1, Node *n2)
{
    p1->next = n2;
    n1->next = n2->next;
    n2->next = n1;
}

int lengthLL(Node* head)
{
    Node* temp = head;
    int count =0;
    while (temp != NULL)
    {
        count++;
        temp= temp->next;
    }
    return count;
}

Node *bubbleSort(Node *head)
{
    if (head == NULL || head->next == NULL )
    {
        return head;
    }
    int size = lengthLL(head);
    
    for (int i=0; i<size ;i++)
    {
    Node *p1 = NULL;
    Node *n1 = head;
    Node *n2 = head->next;

    while (n1->next != NULL)
    {
        if (n1->data > n2->data)
        {
            if (p1 == NULL)
            {
                head = n2;
                n1->next = n2->next;
                n2->next = n1;
            }
            else
            {
                swapNode(p1, n1, n2);
            }

            p1 = n2;
            n2 = n1->next;
        }
        else
        {
            p1 = n1;
            n1 = n1->next;
            n2 = n2->next;
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
        head = bubbleSort(head);
        print(head);
        iterations--;
        cout << endl;
    }
    return 0;
}
