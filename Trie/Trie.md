# Trie Data Structure in C++

## **What is a Trie?**

A **Trie** (pronounced as "try") is a **tree-based data structure** used for storing and searching strings efficiently. It is also called a **prefix tree** because it is used to search words by prefixes.

### **Why use a Trie?**

- **Fast Searching:** Searching for a word in a Trie is **faster** than searching in a normal list or set.
- **Autocomplete:** Used in search engines to suggest words as you type.
- **Spell Checker:** Used to find incorrect words.
- **Dictionary Implementation:** Stores a large number of words efficiently.

---

## **Trie Node Structure**

Each Trie node contains:

1. An array for **26 children** (one for each letter from 'a' to 'z').
2. A **flag (`isEndOfWord`)** to mark the end of a word.

```cpp
struct TrieNode {
    TrieNode* children[26];  // Array to store child nodes
    bool isEndOfWord;        // Marks end of a word

    TrieNode() { // Constructor
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
```

---

## **Trie Class Implementation**

```cpp
class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a'; // Convert character to index (0-25)
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true; // Mark end of the word
    }

    // Search for a word in the Trie
    bool search(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                return false; // If any character is missing, word not found
            }
            node = node->children[index];
        }
        return node->isEndOfWord; // True if it is a word, false if just a prefix
    }
};
```

---

## **Testing the Trie**

```cpp
int main() {
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
```

### **Expected Output**

```
Searching for 'cat': Found
Searching for 'car': Found
Searching for 'can': Not Found
Searching for 'dog': Found
Searching for 'do': Not Found
```

---

## \*\*Understanding Index Calculation (`ch - 'a'`)

Each lowercase character has an ASCII value:

| Letter | ASCII Value | Index Calculation | Final Index |
| ------ | ----------- | ----------------- | ----------- |
| 'a'    | 97          | 97 - 97           | 0           |
| 'b'    | 98          | 98 - 97           | 1           |
| 'c'    | 99          | 99 - 97           | 2           |
| 'm'    | 109         | 109 - 97          | 12          |
| 'z'    | 122         | 122 - 97          | 25          |

This method ensures that characters are mapped to array indices efficiently.

---

## **Trie Memory Representation**

### **Example Trie after inserting "cat", "car", and "dog"**

```
(root)
   |
   c (2)       d (3)
   |           |
   a (0)       o (14)
   |   \       |
   t (19)*  r (17)*  g (6)*
```

(`*` means `isEndOfWord = true`)

---

## **Time Complexity**

| Operation     | Time Complexity |
| ------------- | --------------- |
| Insert a word | O(N)            |
| Search a word | O(N)            |

✅ **Where N is the length of the word**.

---
