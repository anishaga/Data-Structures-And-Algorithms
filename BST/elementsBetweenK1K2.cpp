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

void elementsBetween(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data > k1)
    {
        elementsBetween(root->left, k1, k2);
    }

    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << " ";
    }

    if (root->data < k2)
    {
        elementsBetween(root->right, k1, k2);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();
    int k1, k2;
    cin >> k1;
    cin >> k2;

    elementsBetween(root, k1, k2);

    return 0;
}
