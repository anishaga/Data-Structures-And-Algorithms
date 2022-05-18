#include <iostream>
#include <string>
#include <vector>
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
    bool searchWord(TrieNode *root, string word)
    {
        if (word.length() == 0)
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
            return searchWord(root->children[index], word.substr(1));
        }
    }

public:
    bool searchWord(string word)
    {
        return searchWord(root, word);
    }
};

bool checkPalindrome(string word)
{
    int n = word.size();
    int i = 0;
    int j = n - 1;

    while (i < n / 2)
    {
        if (word[i] != word[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

bool checkPalindrome(vector<string> words)
{
    int n = words.size();
    Trie t;

    for (int i = 0; i < n; i++)
    {
        t.insertWord(words[i]);
        bool ans = checkPalindrome(words[i]);
        if (ans == 1)
        {
            return 1;
        }
    }  

    for (int i=0; i<n; i++)
    {
        int si = 0;
        int end = words[i].size() -1;
        while (si < end)
        {
            char temp = words[i][si];
            words[i][si] = words[i][end];
            words[i][end] = temp;
            si++;
            end--;
        }
        bool ans = t.searchWord(words[i]);
        if (ans == 1)
        {
            return 1;
        }     
    }

    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E:/Code/DSA/input.txt", "r", stdin);
    freopen("E:/Code/DSA/output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<string> words;

    while (n > 0)
    {
        string word;
        cin >> word;
        words.push_back(word);
        n--;
    }

    cout << checkPalindrome(words);

    return 0;
}