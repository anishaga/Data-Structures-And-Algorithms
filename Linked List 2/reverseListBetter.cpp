#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Pair
{
    public:
    Node* head;
    Node* tail;
};

Node * takeInput()
{
    int data;
    cin>>data;

    Node* head = NULL;
    Node* tail = NULL;

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
            tail =n;
        }
        cin >>data;
    }
    return head;
}

void print(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    cout<<endl;
}

Pair reverseListBetter(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;

        return ans;
    }

    Pair temp = reverseListBetter(head->next);
    temp.tail->next = head;
    head->next = NULL;
    Pair ans;
    ans.head = temp.head;
    ans.tail =  head;

    return ans;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int iterations;
    cin>> iterations;

    while(iterations >0)
    {
        Node* head = takeInput();
        print (head);

        Pair temp = reverseListBetter(head);
        print (temp.head);

        iterations--;
        cout<<endl;
    }

    return 0;
}

