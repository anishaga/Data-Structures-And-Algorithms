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

    while(data != -1)
    {
        Node *n = new Node(data);

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next= n;
            tail =n;
        }
        cin>>data;
    }
    return head;
}

int lengthOfLinkedList(Node* head)
{
    Node* temp = head;
    int len = 0;
    while (temp != NULL)
    {   
        len++;
        temp= temp->next;
    }
    return len;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Node* head = takeInput();
    cout<<lengthOfLinkedList(head);

    return 0;
}

