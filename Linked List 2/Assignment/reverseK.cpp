#include <iostream>
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

Node *reverseList(Node *head, Node *prev)
{
    if (head == prev)
    {
        return head;
    }

    Node *temp = reverseList(head->next, prev);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

Node *reverseK(Node *head, int k)
{
    if (head == NULL || k==0)
    {
        return head;
    }
    int size = k;
    Node *temp = head;
    Node *prev = NULL;
    while (size != 0)
    {
        prev = temp;
        temp = temp->next;
        size--;
    }
    Node *dump = prev->next;
    temp = reverseList(head, prev);
    head->next = dump;
    Node* prev1 = head;
    head = temp;
    int i = 1;

    while (dump!= NULL)
    {
        Node *temp = dump;
        size = k;
        while (size != 0)
        {
            prev = temp;
            temp = temp->next;
            size--;
            if (size != 0 && temp == NULL)
            {
                Node*n = prev->next;
                temp = reverseList(dump,prev);
                prev1->next = prev;
                dump->next = n;
                return head;
            }
        }
        Node *n = prev->next;
        temp = reverseList(dump, prev);
        prev1->next = prev;
        dump->next = n;
        prev1 = dump;
        dump =n;
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

        int k;
        cin >> k;

        head = reverseK(head, k);
        print(head);
        iterations--;
        cout << endl;
    }

    return 0;
}
