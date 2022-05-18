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
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        int nodeCount = q.size();
        while (nodeCount > 0)
        {
            BinaryTreeNode<int> *frontNode = q.front();
            cout << frontNode->data << " ";
            q.pop();

            if (frontNode->left != NULL)
            {
                q.push(frontNode->left);
            }

            if (frontNode->right != NULL)
            {
                q.push(frontNode->right);
            }
            nodeCount--;
        }
        cout << endl;
    }
}

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *frontNode = q.front();
        q.pop();

        if (frontNode->left != NULL && frontNode->right != NULL)
        {
            BinaryTreeNode<int> *temp = frontNode->left;

            frontNode->left = frontNode->right;
            frontNode->right = temp;
            q.push(frontNode->right);
            q.push(frontNode->left);
        }

        else if (frontNode->left != NULL && frontNode->right == NULL)
        {
            frontNode->right = frontNode->left;
            q.push(frontNode->left);
            frontNode->left = NULL;
        }
        else if (frontNode->left == NULL && frontNode->right != NULL)
        {
            frontNode->left = frontNode->right;
            q.push(frontNode->right);
            frontNode->right = NULL;
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
    // printTree(root);
    mirrorBinaryTree(root);
    printTree(root);
    return 0;
}
