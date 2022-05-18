#include <iostream>
#include <queue>
#include <stack>
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
        right = NULL;
        left = NULL;
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

        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftData);
            q.push(child);
            frontNode->left = child;
        }

        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightData);
            q.push(child);
            frontNode->right = child;
        }
    }

    return root;
}

vector<int> *findPath(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == k)
    {
        vector<int> *v = new vector<int>();
        v->push_back(root->data);
        return v;
    }

    if (root-> data > k)
    {
      vector<int>* leftOutput = findPath(root->left, k);
      if (leftOutput != NULL)
      {
          leftOutput->push_back(root->data);
          return leftOutput;
      }
    }

    if (root->data < k)
    {
        vector<int>* rightOutput = findPath(root->right, k);
      if (rightOutput != NULL)
      {
          rightOutput->push_back(root->data);
          return rightOutput;
      }
    }

    return NULL;

    // if (k > root->data)
    // {
    //     v->push_back(root->data);
    //     findPath(root->right, k);
    //     return v;
    // }
    // else if (k < root->data)
    // {
    //     v->push_back(root->data);
    //     // s.push(root->data);
    //     findPath(root->left, k);
    //     return v;
    // }
    // else
    // {
    //     cout << root->data << " ";
    //     cout << v->size();
    //     return v;
    //     // while (s.size() != 0)
    //     // {
    //     //     cout << s.top() << " ";
    //     //     s.pop();
    //     // }
    // }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int>* v = findPath(root, k);
    // cout << v->size();
    for (int i=0; i<v->size(); i++)
    {
        cout <<v->at(i)<<" ";
    }
    return 0;
}
