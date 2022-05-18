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

        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(data);
            frontNode->left = child;
            q.push(child);
        }

        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(data);
            frontNode->right = child;
            q.push(child);
        }
    }
    return root;
}

vector<BinaryTreeNode<int> *> *findPath(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == node->data)
    {
        vector<BinaryTreeNode<int> *> *v = new vector<BinaryTreeNode<int> *>();
        v->push_back(root);
        return v;
    }

    vector<BinaryTreeNode<int> *> *leftOutput = findPath(root->left, node);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root);
        return leftOutput;
    }

    vector<BinaryTreeNode<int> *> *rightOutput = findPath(root->right, node);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root);
        return rightOutput;
    }
    return NULL;
}

BinaryTreeNode<int> *LCA(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node1, BinaryTreeNode<int> *node2)
{
    if (root == NULL)
    {
        return NULL;
    }

    vector<BinaryTreeNode<int> *> *v1 = findPath(root, node1);
    vector<BinaryTreeNode<int> *> *v2 = findPath(root, node2);

    if (v1 == NULL && v2 == NULL)
    {
        return NULL;
    }
    else if (v1 == NULL)
    {
        return node2;
    }
    else if (v2 == NULL)
    {
        return node1;
    }
    else
    {
        for (int i = 0; i < v1->size(); i++)
        {
            int num = v1->at(i)->data;

            for (int j = 0; j < v2->size(); j++)
            {
                if (num == v2->at(j)->data)
                {
                    return v2->at(j);
                }
            }
        }
    }
    return NULL;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BinaryTreeNode<int> *root = takeInput();
    int node1Data;
    cin >> node1Data;
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(node1Data);
    int node2Data;
    cin >> node2Data;
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(node2Data);

    if (LCA(root, node1, node2) == NULL)
    {
        cout << -1;
    }
    else
    {
        cout << LCA(root, node1, node2)->data << endl;
    }
    return 0;
}
