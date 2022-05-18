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

class Pair
{
public:
    int maximum;
    int minimum;
    bool isBST;
};

Pair checkBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair ans;
        ans.isBST = 1;
        ans.maximum = INT_MIN;
        ans.minimum = INT_MAX;
        return ans;
    }

    Pair leftOutput = checkBST(root->left);
    Pair rightOutput = checkBST(root->right);

    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum)); 
    bool isBstFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;

    Pair ans;
    ans.minimum = minimum;
    ans.maximum = maximum;
    ans.isBST = isBstFinal;

    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();
    cout << checkBST(root).isBST;
    return 0;
}
