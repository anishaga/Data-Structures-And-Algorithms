#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26]; //Assuming either lowercase or uppercase

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

private:
    void insertWord(TrieNode *root, string word)
    {
        //Base Case

        if (word.size() == 0)
        {
            root->isTerminal = 1;
            return;
        }

        //Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //Recursive Call

        insertWord(child, word.substr(1));
    }

public:
    void insertWord(string word)
    {
        insertWord(root, word);
    }

private:
    bool searchWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] == NULL)
        {
            return 0;
        }
        else
        {
            child = root->children[index];
            return searchWord(child, word.substr(1));
        }
    }

public:
    bool searchWord(string word)
    {
        return searchWord(root, word);
    }

private:
    void removeWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = 0;

            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return;
        }
            removeWord(child, word.substr(1));

        //Remove Child Node (If UseLess)

        if (child->isTerminal == 0)
        {
            for (int i=0; i<26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

public:
    void removeWord(string word)
    {
        removeWord(root, word);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    Trie t;
    t.insertWord("anish");
    t.insertWord("are");
    t.insertWord("and");
    t.insertWord("dot");

    cout << t.searchWord("anish") << endl;
    cout << t.searchWord("and") << endl;
    cout << t.searchWord("are") << endl;
    cout << t.searchWord("a") << endl;
    cout << t.searchWord("do") << endl;
    cout << t.searchWord("den") << endl;

    t.removeWord("dot");
    cout << "After Removal: " << endl;
    cout << t.searchWord("do") << endl;
    cout << t.searchWord("dot") << endl;
    cout << t.searchWord("anish") << endl;
    t.removeWord("anish");
    cout << t.searchWord("anish") << endl;
    t.removeWord("anishaga");

    return 0;
}