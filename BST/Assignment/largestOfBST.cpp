#include <iostream>
#include <queue>
using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *right;
    BinaryTreeNode *left;

    BinaryTreeNode(T data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
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
            q.push(child);
            frontNode->left = child;
        }

        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(data);
            q.push(child);
            frontNode->right = child;
        }
    }
    return root;
}

bool isBST(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->data < min || root->data > max)
    {
        return 0;
    }

    return isBST(root->left, min, root->data - 1) && isBST(root->right, root->data, max);
}

int height(BinaryTreeNode<int>*root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

int largestBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

   if (isBST(root, INT_MIN, INT_MAX))
   {
       return height(root);
   }
   return max(largestBST(root->left),largestBST(root->right));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();

    cout <<largestBST(root);

    return 0;
}
