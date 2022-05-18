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

BinaryTreeNode<int> *takeInput(int a[], int b[], int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(a[0]);

    int i = 0;
    while (b[i] != a[0])
    {
        i++;
    }

    root->left = takeInput(a + 1, b, i);
    root->right = takeInput(a + i + 1, b + i + 1, size - i - 1);
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
    int *b = new int[n];
    inputArray(b, n);

    BinaryTreeNode<int> *root = takeInput(a, b, n);

    // BinaryTreeNode<int> *root = takeInput();
    printTree(root);
    return 0;
}