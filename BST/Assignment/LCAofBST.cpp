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
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete right;
        delete left;
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

        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(data);
            frontNode->left = child;
            q.push(child);
        }

        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(data);
            frontNode->right = child;
            q.push(child);
        }
    }
    return root;
}

BinaryTreeNode<int> *LCA(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node1, BinaryTreeNode<int> *node2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (node1->data == root->data || node2->data == root->data)
    {
        return root;
    }

    if (node1->data < root->data)
    {
        if (node2->data < root->data)
        {
            return LCA(root->left, node1, node2);
        }
        else
        {
            BinaryTreeNode<int> *leftOutput = LCA(root->left, node1, node2);
            BinaryTreeNode<int> *rightOutput = LCA(root->right, node1, node2);

            if (leftOutput == NULL && rightOutput == NULL)
            {
                return NULL;
            }
            else if (rightOutput == NULL)
            {
                return leftOutput;
            }
            else if (leftOutput == NULL)
            {
                return rightOutput;
            }
            else
            {
                return root;
            }
        }
    }
    else
    {
        if (node2->data > root->data)
        {
            return LCA(root->right, node1, node2);
        }
        else
        {
            BinaryTreeNode<int> *leftOutput = LCA(root->left, node1, node2);
            BinaryTreeNode<int> *rightOutput = LCA(root->right, node1, node2);

            if (leftOutput == NULL && rightOutput == NULL)
            {
                return NULL;
            }
            else if (rightOutput == NULL)
            {
                return leftOutput;
            }
            else if (leftOutput == NULL)
            {
                return rightOutput;
            }
            else
            {
                return root;
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();

    int node1Data;
    cin >> node1Data;
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(node1Data);

    int node2Data;
    cin >> node2Data;
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(node2Data);

    if (LCA(root, node1, node2) == NULL)
    {
        cout << -1;
    }
    else
    {
        cout << LCA(root, node1, node2)->data << endl;
    }
    return 0;
}
