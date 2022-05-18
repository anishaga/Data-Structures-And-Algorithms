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

// int sumOf(BinaryTreeNode<int>* root, int num)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     if (root->data >= num)
//     {
//         return root->data + sumOf(root->right, num) + sumOf(root->left, num);
//     }
//     else
//     {
//         return sumOf(root->left, num);
//     }
// }

int replaceSum(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
    {
        return sum;
    }

    sum = replaceSum(root->right, sum);
    root->data = root->data + sum;
    sum = replaceSum(root->left, root->data);
    
    return sum;
}

void printTree(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            if (q.size() == 0)
            {
                return;
            }
            q.push(NULL);
            cout <<endl;
        }
        else
        {
        cout << frontNode->data << " ";

        if (frontNode->left != NULL)
        {
            q.push(frontNode->left);
        }

        if (frontNode->right != NULL)
        {
            q.push(frontNode->right);
        }
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
    replaceSum(root, 0);
    printTree(root);
    return 0;
}
