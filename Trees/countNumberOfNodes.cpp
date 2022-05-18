#include <iostream>
using namespace std;
#include <vector>
#include <queue>

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
};

TreeNode<int> *takeInput()
{
    int data;
    // cout<<"Enter Root Data"<<endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int> *frontNode = q.front();
        q.pop();

        int num;
        // cout<<"Enter Number Of Children Of "<<frontNode->data<<" Node:"<<endl;
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            // cout<<"Enter Data Of "<<i<<" Child Of "<<frontNode->data<<" Node"<<endl;
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
        cout << frontNode->data << ":";
        q.pop();

        for (int i = 0; i < frontNode->children.size(); i++)
        {
            cout << frontNode->children[i]->data << ",";
            q.push(frontNode->children[i]);
        }
        cout << endl;
    }
}

int countNodes(TreeNode<int> *root)
{
    int ans = 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + countNodes(root->children[i]);
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
    printTree(root);

    cout << countNodes(root);

    return 0;
}
