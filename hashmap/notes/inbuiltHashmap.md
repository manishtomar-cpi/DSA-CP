# HashMap in C++

A **HashMap** is a data structure that provides efficient **key-value** pair storage. It allows fast insertion, deletion, and lookup operations in **O(1)** on average.

C++ provides two built-in hash map implementations in the **Standard Template Library (STL)**:

1. **`std::map` (Ordered Map)** → Implemented using a **Red-Black Tree** (Balanced BST). Stores keys in sorted order.
2. **`std::unordered_map` (Unordered Map)** → Implemented using a **Hash Table**. Does not maintain any order.

---

## 1. `std::map` (Ordered Map)

- Stores elements in **sorted order** based on keys.
- Implemented using a **Red-Black Tree**.
- Provides **O(log n)** time complexity for insertion, deletion, and search.
- Useful when ordered traversal of keys is needed.

### Syntax and Examples

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> myMap;

    // Insertion
    myMap.insert({1, "Apple"});
    myMap.insert({3, "Banana"});
    myMap.insert({2, "Cherry"});

    // Traversal using iterator
    cout << "Traversing using iterator:" << endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    // Traversal using range-based for loop
    cout << "\nTraversing using range-based for loop:" << endl;
    for (auto &entry : myMap) {
        cout << entry.first << " -> " << entry.second << endl;
    }
    return 0;
}
```

### Functions in `std::map`

| Function               | Description                                                 |
| ---------------------- | ----------------------------------------------------------- |
| `insert({key, value})` | Inserts key-value pair                                      |
| `erase(key)`           | Removes element with given key                              |
| `find(key)`            | Returns iterator to element if found, otherwise `map.end()` |
| `count(key)`           | Returns `1` if key exists, else `0`                         |
| `size()`               | Returns number of elements                                  |
| `empty()`              | Checks if map is empty                                      |
| `clear()`              | Removes all elements                                        |
| `begin(), end()`       | Iterators for traversal                                     |

---

## 2. `std::unordered_map` (Unordered Map)

- Stores elements in **random order** (depends on hashing function).
- Implemented using a **Hash Table**.
- Provides **O(1)** average time complexity for insertion, deletion, and search.
- Useful when **order does not matter**, and we need fast lookups.

### Syntax and Examples

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> myMap;

    // Insertion
    myMap.insert({1, "Apple"});
    myMap.insert({3, "Banana"});
    myMap.insert({2, "Cherry"});

    // Traversal using iterator
    cout << "Traversing using iterator:" << endl;
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        cout << it->first << " -> " << it->second << endl;
    }

    // Traversal using range-based for loop
    cout << "\nTraversing using range-based for loop:" << endl;
    for (auto &entry : myMap) {
        cout << entry.first << " -> " << entry.second << endl;
    }
    return 0;
}
```

### Functions in `std::unordered_map`

| Function               | Description                                                           |
| ---------------------- | --------------------------------------------------------------------- |
| `insert({key, value})` | Inserts key-value pair                                                |
| `erase(key)`           | Removes element with given key                                        |
| `find(key)`            | Returns iterator to element if found, otherwise `unordered_map.end()` |
| `count(key)`           | Returns `1` if key exists, else `0`                                   |
| `size()`               | Returns number of elements                                            |
| `empty()`              | Checks if map is empty                                                |
| `clear()`              | Removes all elements                                                  |
| `begin(), end()`       | Iterators for traversal                                               |

---

## Key Differences between `map` and `unordered_map`

| Feature            | `std::map` (Ordered)        | `std::unordered_map` (Unordered) |
| ------------------ | --------------------------- | -------------------------------- |
| **Implementation** | Red-Black Tree (BST)        | Hash Table                       |
| **Key Order**      | Sorted order                | Random order                     |
| **Insertion Time** | O(log n)                    | O(1) (average)                   |
| **Deletion Time**  | O(log n)                    | O(1) (average)                   |
| **Search Time**    | O(log n)                    | O(1) (average)                   |
| **Use Case**       | When sorted keys are needed | When fast lookups are needed     |

---

## When to Use Which?

- Use **`std::map`** when **sorted order** of keys is required.
- Use **`std::unordered_map`** when **fast lookups** are required and order is not important.
