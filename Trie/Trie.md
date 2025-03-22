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
