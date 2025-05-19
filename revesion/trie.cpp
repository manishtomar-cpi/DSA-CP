#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    bool isLast;
    TrieNode *child[26];

    TrieNode()
    {
        isLast = false;

        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string str)
    {
        TrieNode *temp = root;
        for (int i = 0; i < str.size(); i++)
        {
            int index = str[i] - 'a';
            if (temp->child[index] == nullptr)
            {
                temp->child[index] = new TrieNode();
            }
            temp = temp->child[index];
        }
        temp->isLast = true;
    }

    bool search(string str)
    {
        TrieNode *temp = root;
        for (int i = 0; i < str.size(); i++)
        {
            int index = str[i] - 'a';
            if (temp->child[index] == nullptr)
            {
                return false;
            }
            else
            {
                temp = temp->child[index];
            }
        }
        return temp->isLast ? true : false;
    }
};

int main()
{
    Trie trie;

    // Insert words
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");

    // Search for words
    cout << "Searching for 'cat': " << (trie.search("cat") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'car': " << (trie.search("car") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'can': " << (trie.search("can") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'dog': " << (trie.search("dog") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'do': " << (trie.search("do") ? "Found" : "Not Found") << endl;

    return 0;
}