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
    cout<<endl;
}

Node* deleteNode(Node* head, int m, int n)
{
    if (head == NULL)
    {
        return head;
    }
    if (m==0)
    {
        return NULL;
    }
    int count=0;
    Node* temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        if (count == m)
        {
            count = 0;
            while (count != n)
            {
                if (temp == NULL)
                {
                        return head;
                }
            temp=temp->next;
            prev->next = temp;
            count ++;
            }
            count = 0;
        }
        else
        {
        count++;
        prev = temp;
        temp=temp->next;
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
        // print(head);

        int m, n;
        cin >> m >> n;

        head = deleteNode(head,m,n);
        print(head);
               
        iterations--;
        cout << endl;
    }

    return 0;
}
