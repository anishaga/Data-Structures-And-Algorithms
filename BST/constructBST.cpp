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
        delete left;
        delete right;
    }
};

void inputArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

BinaryTreeNode<int> *constructBST(int a[], int n)
{
    if (n == 0)
    {
        return NULL;
    }

    int index = n / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(a[index]);
    root->left = constructBST(a, index);
    if (n % 2 != 0)
    {
        root->right = constructBST(a + index + 1, index);
    }
    else
    {
        root->right = constructBST(a + index + 1, index-1);
    }

    return root;
}

void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    int *a = new int[n];
    inputArray(a, n);

    BinaryTreeNode<int> *root = constructBST(a, n);
    printTree(root);
    return 0;
}
