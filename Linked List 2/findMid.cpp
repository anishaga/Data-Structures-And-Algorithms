#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node (int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node* takeInput()
{
    int data;
    cin>>data;

    Node* head= NULL;
    Node* tail = NULL;

    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head =n; 
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        cin>>data;
    }
    return head;
}

void print (Node* head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
    }

    cout<<endl;
}

Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while ((fast != NULL) && (fast->next != NULL))
    {
        slow= slow->next;
        fast = fast->next->next;
    }

    return slow;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int iterations;
    cin>>iterations;

    while (iterations >0)
    {
    Node* head = takeInput();
    if (head != NULL)
    {
    Node *temp = findMid(head);
    cout<<temp->data;
    }
    iterations--;
    cout<<endl;
    }

    return 0;
}

