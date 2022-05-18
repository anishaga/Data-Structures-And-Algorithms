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
            cout << frontNode->children[i]->data << " ";
            q.push(frontNode->children[i]);
        }
        cout << endl;
    }
}

bool containsX(TreeNode<int> *root, int x)
{
    if (root->data == x)
    {
        return 1;
    }
    bool ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = containsX(root->children[i], x);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    TreeNode<int> *root = takeInput();
    // printTree(root);
    int x;
    cin >> x;

    cout << containsX(root, x) << endl;

    return 0;
}
