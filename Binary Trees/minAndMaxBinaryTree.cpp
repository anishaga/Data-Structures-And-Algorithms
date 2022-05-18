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
            cout << "L" << frontNode->right->data << ",";
            q.push(frontNode->right);
        }
        cout << endl;
    }
}

pair<int, int> minMax(BinaryTreeNode<int> *root)
{
    pair<int, int> p;
    p.first = root->data;
    p.second = root->data;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *frontNode = q.front();
        q.pop();

        if (frontNode->data > p.first)
        {
            p.first = frontNode->data;
        }
        if (frontNode->data < p.second)
        {
            p.second = frontNode->data;
        }

        if (frontNode->right != NULL)
        {
            q.push(frontNode->right);
        }

        if (frontNode->left != NULL)
        {
            q.push(frontNode->left);
        }
    }
    return p;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    pair<int, int> p = minMax(root);
    cout << "Min: " << p.second << endl;
    cout << "Max: " << p.first << endl;

    return 0;
}
