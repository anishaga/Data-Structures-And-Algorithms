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

class Pair
{
public:
    int minimum;
    int maximum;
    bool isBST;
    int height;
};

Pair largestBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.minimum = INT_MAX;
        ans.maximum = INT_MIN;
        ans.isBST = 1;
        ans.height = 0;

        return ans;
    }

    Pair leftOutput = largestBST(root->left);
    Pair rightOutput = largestBST(root->right);


    Pair ans;
 
    if ((root->data > leftOutput.maximum) && (root->data < rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST))
    {
        ans.minimum = min(leftOutput.minimum, min(root->data, rightOutput.minimum));
        ans.maximum = max(leftOutput.maximum, max(root->data, rightOutput.maximum));
        ans.height = 1 + leftOutput.height + rightOutput.height;
        ans.isBST =1;
    }
    else
    {
         ans.minimum = 0;
        ans.maximum = 0;
        ans.height = max(leftOutput.height, rightOutput.height);
        ans.isBST = 0;
    }
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();

    cout << largestBST(root).height;

    return 0;
}
