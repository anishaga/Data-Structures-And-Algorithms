#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode
{
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete right;
        delete left;
    }
};

BinaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int>* frontNode = q.front();
        q.pop();

        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftData);
            q.push(child);
            frontNode->left = child;
        }

        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightData);
            q.push(child);
            frontNode->right = child;
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);

    while (q.size() != 0)
    {
        BinaryTreeNode<int>* frontNode = q.front();
        q.pop();

        if (frontNode == NULL)
        {
            if (q.size() == 0)
            {
                break;
            }
            q.push(NULL);
            cout << endl;
        }
        else
        {
            cout << frontNode->data <<" ";
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
//  void printTree(BinaryTreeNode<int> *node)
//     {
//         if (node == NULL)
//         {
//             return;
//         }

//         cout << node->data << ": ";

//         if (node->left != NULL)
//         {
//             cout << "L" << node->left->data << ",";
//         }

//         if (node->right != NULL)
//         {
//             cout << "R" << node->right->data;
//         }
//         cout << endl;
//         printTree(node->left);
//         printTree(node->right);
//     }

void duplicateNode(BinaryTreeNode<int>* root)
{
    if (root == NULL)
    {
        return;
    }

    BinaryTreeNode<int>* temp = new BinaryTreeNode<int>(root->data);
    temp->left = root->left;
    root->left = temp;

    duplicateNode(temp->left);
    duplicateNode(root->right);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    BinaryTreeNode<int>* root = takeInput();
    duplicateNode(root);
    printTree(root);
    return 0;
}
