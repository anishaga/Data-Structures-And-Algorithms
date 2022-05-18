#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInput()
{
    int data;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int> *frontNode = q.front();
        q.pop();
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cin >> data;
            TreeNode<int> *child = new TreeNode<int>(data);
            q.push(child);
            frontNode->children.push_back(child);
        }
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int> *frontNode = q.front();
        q.pop();
        cout << frontNode->data << ": ";
        for (int i = 0; i < frontNode->children.size(); i++)
        {
            cout << frontNode->children[i]->data << ",";
            q.push(frontNode->children[i]);
        }
        cout << endl;
    }
}

TreeNode<int> *nextLarger(TreeNode<int> *root, int n)
{
    TreeNode<int> * largeNode = NULL;
    queue<TreeNode<int> *> q;
    q.push(root);
    while (q.size() != 0)
    {
        TreeNode<int> *frontNode = q.front();
        q.pop();
        if (largeNode == NULL)
        {
            if (frontNode->data > n)
            {
                largeNode = frontNode;
            }
        }
        else
        {
            if (frontNode->data > n && frontNode->data < largeNode->data)
            {
                largeNode = frontNode;
            }
        }

        for (int i=0; i<frontNode->children.size(); i++)
        {
            q.push(frontNode->children[i]);
        }
    }
    return largeNode;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    TreeNode<int> *root = takeInput();
    printTree(root);

    TreeNode<int> * ans = nextLarger(root, n);
    if (ans != NULL)
    {
        cout <<ans->data;
    }

    return 0;
}
