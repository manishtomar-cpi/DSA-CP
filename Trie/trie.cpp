#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    bool isLast; // use to detect the last char of the word
    TrieNode *childrens[26];

    TrieNode()
    {
        isLast = false;

        // making all childs to null
        for (int i = 0; i < 26; i++)
        {
            childrens[i] = nullptr;
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
    /*
    Algorithm Steps:
    1: Start at the root node.
    2: For each character ch in the word:
            Convert ch into an index using index = ch - 'a'.
            If children[index] is nullptr:
                Create a new TrieNode at that index.
            Move to the next node (node = node->children[index]).
    3: Mark the last node as the end of the word (isEndOfWord = true).
    */
    void insert(string word)
    {
        TrieNode *temp = root;
        // traverse the word
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a'; // this is the acctual index of the word according to the childs array
            if (temp->childrens[index] == nullptr)
            {                                            // means this char is not added yet
                temp->childrens[index] = new TrieNode(); // make the new node, now the index of new node is stored in the exsting index that is not null anymore
            }
            // move temp to the new index to add next letter
            temp = temp->childrens[index];
        }
        temp->isLast = true; // because it is the last char of that word
    }
    /*
    Algorithm Steps:
    1: Start at the root node.
    2: For each character ch in the word:
        Convert ch into an index using index = ch - 'a'.
        If children[index] is nullptr → Word does not exist, return false.
        Move to the next node (node = node->children[index]).
    3: After processing all characters, check:
            If isEndOfWord = true → Word exists (return true).
            Otherwise → Only a prefix exists, but not a full word (return false).
    */

    bool search(string word)
    {
        // first traverse each char and search
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (temp->childrens[index] == nullptr)
            { // means the char is nit present in the childs array
                return false;
            }
            else
            {
                temp = temp->childrens[index]; // move to that char to find the next one
            }
                }
        // now check it is last word or not
        return temp->isLast;
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
