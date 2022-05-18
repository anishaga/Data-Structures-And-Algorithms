#include <bits/stdc++.h>
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

bool checkBST(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->data < min || root->data > max)
    {
        return 0;
    }

    return checkBST(root->left,min,root->data-1) && checkBST(root->right,root->data,max);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();
    cout << checkBST(root, INT_MIN, INT_MAX);
    return 0;
}
