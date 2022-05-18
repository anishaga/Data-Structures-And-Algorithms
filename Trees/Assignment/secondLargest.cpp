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
        for (int i = 0; i < children.size; i++)
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

TreeNode<int> *secondLargest(TreeNode<int> *root)
{
    TreeNode<int> *first = NULL;
    TreeNode<int> *second = NULL;
    queue<TreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int> *frontNode = q.front();
        q.pop();
        if (first == NULL)
        {
            first = frontNode;
        }
        else
        {
            if (frontNode->data > first->data)
            {
                second = first;
                first = frontNode;
            }
            else
            {
                if (second == NULL)
                {
                    second = frontNode;
                }
                else
                {
                    if (second->data < frontNode->data)
                    {
                        second = frontNode;
                    }
                }
            }
        }
        for (int i = 0; i < frontNode->children.size(); i++)
        {
            q.push(frontNode->children[i]);
        }
    }
    return second;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    TreeNode<int> *root = takeInput();
    // printTree(root);
    TreeNode<int> *ans = secondLargest(root);
    if (ans != NULL)
    {
        cout << ans->data;
    }

    return 0;
}
