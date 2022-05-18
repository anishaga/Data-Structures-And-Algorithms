#include <iostream>
#include <queue>
using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }

    ~BinaryTreeNode()
    {
        delete right;
        delete left;
    }
};

class Node
{
public:
    BinaryTreeNode<int> *data;
    Node *next;

    Node(BinaryTreeNode<int> *data)
    {
        this->data = data;
        next = NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *frontNode = q.front();
        q.pop();

        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftData);
            q.push(child);
            frontNode->left = child;
        }

        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightData);
            q.push(child);
            frontNode->right = child;
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *frontNode = q.front();
        q.pop();
        cout << frontNode->data << ": ";

        if (frontNode->left != NULL)
        {
            cout << "L" << frontNode->left->data << ",";
            q.push(frontNode->left);
        }

        if (frontNode->right != NULL)
        {
            cout << "R" << frontNode->right->data;
            q.push(frontNode->right);
        }
        cout << endl;
    }
}

vector<Node *> levelWise(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    vector<Node *> v;
    Node *head = NULL;
    Node *tail = NULL;

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            v.push_back(head);
            head = NULL;
            tail = NULL;
            if (q.size() == 0)
            {
                break;
            }
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            Node *n = new Node(frontNode);
            if (head == NULL)
            {
                tail = n;
                head = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }

            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
        }
    }
    return v;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();

    vector<Node *> v = levelWise(root);
    
    for (int i = 0; i < v.size(); i++)
    {
        while (v[i] != NULL)
        {
            cout << v[i]->data->data << " ";
            v[i] = v[i]->next;
        }
        cout << endl;
    }
    return 0;
}
