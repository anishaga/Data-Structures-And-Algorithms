#include <iostream>
#include <queue>
#include <vector>
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

void mergeSorted(vector<int> &v, int si, int end)
{
    int mid = (si + end) / 2;
    int i = si;
    int j = mid + 1;
    vector<int> temp;

    while (i <= mid && j <= end)
    {
        if (v[i] <= v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(v[i]);
        i++;
    }

    while (j <= end)
    {
        temp.push_back(v[j]);

        j++;
    }

    int k = 0;

    for (i = si; i <= end; i++)
    {
        v[i] = temp[k];
        k++;
    }
}

void mergeSort(vector<int> &v, int si, int end)
{
    if (si >= end)
    {
        return;
    }

    int mid = (si + end) / 2;
    mergeSort(v, si, mid);
    mergeSort(v, mid + 1, end);
    mergeSorted(v, si, end);
}

void pairSum(BinaryTreeNode<int> *root, int s)
{
    vector<int> v;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *frontNode = q.front();
        q.pop();
        v.push_back(frontNode->data);

        if (frontNode->left != NULL)
        {
            q.push(frontNode->left);
        }
        if (frontNode->right != NULL)
        {
            q.push(frontNode->right);
        }
    }

    mergeSort(v, 0, v.size() - 1);

    int i = 0;
    int j = v.size() - 1;

    while (i <= j)
    {
        if (v[i] + v[j] == s)
        {
            cout << v[i] << " " << v[j] << endl;
            i++;
            j--;
        }
        else if (v[i] + v[j] > s)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    pairSum(root, s);
    return 0;
}
