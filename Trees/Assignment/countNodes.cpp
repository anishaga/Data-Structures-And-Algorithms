#include <iostream>
#include <queue>
#include <vector>
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

int countNodes(TreeNode<int> *root, int x)
{
    int count = 0;
    if (root->data > x)
    {
        count = 1;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        count = countNodes(root->children[i], x) + count;
    }
    return count;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    TreeNode<int> *root = takeInput();
    int x;
    cin >> x;

    cout << countNodes(root, x);
    return 0;
}
