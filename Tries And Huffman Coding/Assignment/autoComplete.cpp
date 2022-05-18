#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char data;
    bool isTerminal;
    TrieNode **children;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
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
        if (word.size() == 0)
        {
            root->isTerminal = 1;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] == NULL)
        {
            child = new TrieNode(word[0]);

            root->children[index] = child;
        }
        else
        {
            child = root->children[index];
        }
        insertWord(child, word.substr(1));
    }

public:
    void insertWord(string word)
    {
        insertWord(root, word);
    }

private:
    TrieNode *searchWord(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] == NULL)
        {
            return NULL;
        }
        else
        {
            return searchWord(root->children[index], word.substr(1));
        }
    }

private:
    void autoComplete(TrieNode *root, string word, string output)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->data != NULL)
        {
            output = output + root->data;
        }

        if (root->isTerminal == 1)
        {
            cout << word + output << endl;
        }

        int counter = 0;
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                autoComplete(root->children[i], word, output);
            }
        }
        return;
    }

public:
    void autoComplete(string word)
    {
        string output;
        autoComplete(searchWord(root, word), word, output);
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    Trie t;
    while (n > 0)
    {
        string s;
        cin >> s;
        t.insertWord(s);
        n--;
    }

    string s;
    cin >> s;
    t.autoComplete(s);
    return 0;
}