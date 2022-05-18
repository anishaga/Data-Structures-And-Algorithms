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

void sortedData(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    if (root->right == NULL && root->left == NULL)
    {
        v.push_back(root->data);
        return;
    }

    sortedData(root->left, v);
    v.push_back(root->data);
    sortedData(root->right, v);

    // vector<int>* leftOutput = sortedData(root->left);
    // if (leftOutput != NULL)
    // {
    //     leftOutput->push_back(root->data);
    //     return leftOutput;
    // }

    // vector<int>* rightOutput = sortedData(root->right);
    // if (rightOutput != NULL)
    // {
    //     rightOutput->push_back(root->data);
    //     return rightOutput;
    // }
    // return NULL;
}

void pairSumBST(BinaryTreeNode<int> *root, int s)
{
    vector<int> v;
    sortedData(root, v);

    int i = 0;
    int j = v.size() - 1;

    while (i < j)
    {
        if (v[i] + v[j] == s)
        {
            cout << v[i] <<" " << v[j] << endl;
            i++;
            j--;
        }
        else if (v[i] + v[j] < s)
        {
            i++;
        }
        else
        {
            j--;
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
    int s;
    cin >> s;
    pairSumBST(root, s);
    return 0;
}
