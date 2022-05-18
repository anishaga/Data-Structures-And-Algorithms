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

int depth(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(depth(root->left), depth(root->right));
}

bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 1;
    }

    if (depth(root->left) - depth(root->right) >= 1 || depth(root->right) - depth(root->left) >= 1)
    {
        return 0;
    }

   return isBalanced(root->left) && isBalanced(root->right);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    cout << isBalanced(root);
    return 0;
}
