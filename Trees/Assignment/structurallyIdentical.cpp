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

bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1->children.size() != root2->children.size())
    {
        return 0;
    }
    else
    {
        queue<TreeNode<int> *> q1;
        q1.push(root1);
        queue<TreeNode<int> *> q2;
        q2.push(root2);

        while (q1.size() != 0)
        {
            TreeNode<int> *frontNode1 = q1.front();
            TreeNode<int> *frontNode2 = q2.front();
            q1.pop();
            q2.pop();
            if (frontNode1->data != frontNode2->data)
            {
                return 0;
            }

            for (int i = 0; i < frontNode1->children.size(); i++)
            {
                q1.push(frontNode1->children[i]);
                q2.push(frontNode2->children[i]);
            }
        }
    }
    return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    TreeNode<int> *root1 = takeInput();
    // printTree(root1);

    TreeNode<int> *root2 = takeInput();
    // printTree(root2);

    cout << isIdentical(root1, root2) << endl;
    return 0;
}
