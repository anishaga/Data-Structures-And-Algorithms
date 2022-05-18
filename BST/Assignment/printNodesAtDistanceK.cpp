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

vector<BinaryTreeNode<int> *> *findNode(BinaryTreeNode<int> *root, int n)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        vector<BinaryTreeNode<int> *> *v = new vector<BinaryTreeNode<int> *>();
        v->push_back(root);
        return v;
    }

    vector<BinaryTreeNode<int> *> *leftOutput = findNode(root->left, n);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root);
        return leftOutput;
    }
    vector<BinaryTreeNode<int> *> *rightOutput = findNode(root->right, n);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root);
        return rightOutput;
    }
    return NULL;
}

void printNodeAtDistance(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }

    printNodeAtDistance(root->left, k - 1);
    printNodeAtDistance(root->right, k - 1);
}

int printNodesAtk(BinaryTreeNode<int> *root, BinaryTreeNode<int> *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        printNodeAtDistance(root, k);
        return 0;
    }

    int dl = printNodesAtk(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printNodeAtDistance(root->right, k - dl - 2);
        }
        return 1 + dl;
    }
    int dr = printNodesAtk(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printNodeAtDistance(root->left, k - dr - 2);
        }
        return 1 + dr;
    }

    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();
    // printTree(root);
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<BinaryTreeNode<int> *> *v = findNode(root, n);
    printNodesAtk(root, v->at(0), k);

    return 0;
}
