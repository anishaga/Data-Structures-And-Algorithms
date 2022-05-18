#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *right;
    BinaryTreeNode *left;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete right;
        delete left;
    }
};

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

private:
    bool hasData(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return 0;
        }

        if (node->data == data)
        {
            return 1;
        }

        else if (node->data < data)
        {
            return hasData(node->right, data);
        }

        else
        {
            return hasData(node->left, data);
        }
    }

    BinaryTreeNode<int> *insertData(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if (node->data > data)
        {
            node->left = insertData(node->left, data);
        }

        else
        {
            node->right = insertData(node->right, data);
        }

        return node;
    }

    BinaryTreeNode<int> *deleteData(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (node->data == data)
        {
            // When Leaf Node
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            // When Only One Child
            else if (node->left == NULL || node->right == NULL)
            {
                if (node->left != NULL)
                {
                    BinaryTreeNode<int> *temp = node->left;
                    node->left = NULL;
                    delete node;
                    return temp;
                }
                else
                {
                    BinaryTreeNode<int> *temp = node->right;
                    node->right = NULL;
                    delete node;
                    return temp;
                }
            }

            // When Both Child
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right, rightMin);
                return node;
            }
        }

        else if (node->data > data)
        {
            node->left = deleteData(node->left, data);
            return node;
        }

        else
        {
            node->right = deleteData(node->right, data);
            return node;
        }
    }

    void printTree(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            return;
        }

        cout << node->data << ": ";

        if (node->left != NULL)
        {
            cout << "L" << node->left->data << ",";
        }

        if (node->right != NULL)
        {
            cout << "R" << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }

public:
    bool hasData(int data)
    {
        return hasData(root, data);
    }

    void insertData(int data)
    {
        this->root = insertData(root, data);
    }

    void deleteData(int data)
    {
        this->root = deleteData(root, data);
    }

    void printTree()
    {
        printTree(root);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(20);
    b.insertData(7);
    b.insertData(3);
    b.insertData(15);

    b.printTree();

    cout << b.hasData(20)<<endl;

    b.deleteData(10);
    b.deleteData(100);
    b.printTree();
    return 0;
}
