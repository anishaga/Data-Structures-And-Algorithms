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

Node *swapNode(Node *head, int i, int j)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *prev1 = NULL;
    Node *index1 = head;
    Node *prev2 = NULL;
    Node *index2 = head;

    int k = i;
    int l = j;

    while (i != 0)
    {
        prev1 = temp;
        temp = temp->next;
        index1 = temp;
        i--;
    }

    temp = head;
    while (j != 0)
    {
        prev2 = temp;
        temp = temp->next;
        index2 = temp;
        j--;
    }

    if (k == 0 || l == 0)
    {
        if (k - l == 1 || k - l == -1)
        {
            if (k == 0)
            {
                temp = index2->next;
                head = index2;
                index2->next = index1;
                index1->next = temp;
            }
            else
            {
                temp = index1->next;
                head = index1;
                index1->next = index2;
                index2->next = temp;
            }
        }
        else
        {
            if (k == 0)
            {
                temp = index2->next;
                head = index2;
                index2->next = index1->next;
                prev2->next = index1;
                index1->next = temp;
            }
            else
            {
                temp = index1->next;
                head = index1;
                index1->next = index2->next;
                prev1->next = index2;
                index2->next = temp;
            }
        }
        return head;
    }

    if (k - l == 1 || k - l == -1)
    {
        temp = index2->next;
        prev1->next = index2;
        index2->next = index1;
        index1->next = temp;
    }
    else
    {
        temp = index2->next;
        prev1->next = index2;
        index2->next = index1->next;
        prev2->next = index1;
        index1->next = temp;
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

        int i, j;
        cin >> i >> j;

        head = swapNode(head, i, j);
        print(head);

        iterations--;
        cout << endl;
    }

    return 0;
}
