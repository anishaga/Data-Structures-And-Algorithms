#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
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
    bool searchWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return 1;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] == NULL)
        {
            return 0;
        }
        else
        {
            return searchWord(root->children[index], word.substr(1));
        }
    }

public:
    bool searchWord(string word)
    {
        return searchWord(root, word);
    }

private:
    void insertWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] == NULL)
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else
        {
            child = root->children[index];
        }

        insertWord(child,word.substr(1));

    }

public:
    void insertWord(string word)
    {
        if (searchWord(word) == 1)
        {
            return;
        }
        insertWord(root, word);
        while (word.size() != 0)
        {
            word = word.substr(1);
            insertWord(word);
        }
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
        string word;
        cin >> word;
        t.insertWord(word);
        n--;
    }

    string findWord;
    cin >> findWord;

    cout << t.searchWord(findWord);

    return 0;
}