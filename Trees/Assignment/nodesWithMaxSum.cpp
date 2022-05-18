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

int sumOf(TreeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + root->children[i]->data;
    }
    return sum;
}

int maxSum(TreeNode<int> *root)
{
    int sum = sumOf(root);
    int nodeData = root->data;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int> * frontNode = q.front();
        q.pop();

        for (int i = 0; i < frontNode->children.size(); i++)
        {
            if (sum < sumOf(frontNode->children[i]))
            {
                nodeData = frontNode->children[i]->data;
                sum = sumOf(frontNode->children[i]);
            }
            q.push(frontNode->children[i]);
        }
    }
    return nodeData;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    TreeNode<int> *root = takeInput();
    // printTree(root);

    cout << maxSum(root);
    return 0;
}
