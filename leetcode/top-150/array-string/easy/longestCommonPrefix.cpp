#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode
{
public:
    TrieNode *childs[26];
    bool isLast;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            childs[i] = nullptr;
        }
        isLast = false;
    }
};

class Trie
{
private:
    TrieNode *head;

public:
    Trie()
    {
        head = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *temp = head;
        // traverse the word
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a'; // this is the acctual index of the word according to the childs array
            if (temp->childs[index] == nullptr)
            {                                         // means this char is not added yet
                temp->childs[index] = new TrieNode(); // make the new node, now the index of new node is stored in the exsting index that is not null anymore
            }
            // move temp to the new index to add next letter
            temp = temp->childs[index];
        }
        temp->isLast = true; // because it is the last char of that word
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        // fill all the words inside trie
        for (int i = 0; i < strs.size(); i++)
        {
            insert(strs[i]);
        }

        // Now check the prefixs
        TrieNode *temp = head;
        string prefix = "";

        while (true)
        {
            int nextIndex = -1; // why -1 ? because on first traverse we will get the first char which is prefix then we will traverse his childs
            int count = 0;      // counting the childs
            for (int i = 0; i < 26; i++)
            {
                if (temp->childs[i] != nullptr)
                {
                    nextIndex = i;
                    count++;
                }
            }
            if (count != 1 || temp->isLast)
            { // when more then one childs of the node or all words in vector is same menas all are prefix then we will reach end
                return prefix;
            }
            prefix += char(nextIndex + 'a'); //! syntax to add new char in string in this case
            temp = temp->childs[nextIndex];
        }
        return prefix;
    }
};

int main()
{
    vector<string> vec = {"flower", "flower", "flower"};
    Trie t1;

    cout << t1.longestCommonPrefix(vec) << endl;

    return 0;
}