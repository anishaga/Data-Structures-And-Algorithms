#include <iostream>
using namespace std;
#include <vector>

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
    // cout << "Enter Data:"<<endl; 
    cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);

    // cout<<"Enter Number Of Children:"<<endl;
    int num;
    cin >> num;

    while (num > 0)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
        num--;
    }

    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int> *root = takeInput();
    printTree(root);
    return 0;
}
