# Deep Dive into HashMap: Bucket Array, Hash Function, and Collision Handling

A **HashMap** is a data structure that enables fast retrieval of data using key-value pairs. It is widely used in applications requiring efficient lookup, insertion, and deletion operations.

---

## 1. Bucket Array
### What is a Bucket Array?
A **bucket array** is an array where each index (or bucket) stores elements based on a computed hash value. The bucket holds one or more key-value pairs that share the same computed index.

### How it Works:
- The **array size (N)** is predetermined.
- The **hash function** computes an index for each key.
- Each bucket can hold multiple values in case of collisions (e.g., via chaining).

#### **Example:** Bucket Array Representation
| Index | Stored Elements |
|--------|----------------|
| 0 | - |
| 1 | (11, "Apple") |
| 2 | (12, "Banana"), (22, "Cherry") |
| 3 | - |

Here, **keys 12 and 22** have the same bucket index due to hash collision.

---

## 2. Hash Function
### What is a Hash Function?
A **hash function** maps a key to an index within the bucket array. It should distribute values **uniformly** to minimize collisions.

### Properties of a Good Hash Function:
- **Deterministic**: Produces the same output for the same input.
- **Uniform Distribution**: Spreads keys across the array to reduce clustering.
- **Efficient**: Computation should be quick.

### **Example Hash Function:**
```cpp
int hashFunction(int key, int bucketSize) {
    return key % bucketSize;  // Modulo operation ensures a valid index.
}
```

#### Example Calculations:
| Key | Hash Function Output (for `bucketSize = 10`) |
|------|------------------|
| 12 | 12 % 10 = 2 |
| 22 | 22 % 10 = 2 (collision) |
| 33 | 33 % 10 = 3 |

---

## 3. Collision Handling
### What is a Collision?
A **collision** occurs when multiple keys produce the same index. To handle collisions, we use **collision resolution techniques**.

### **Techniques for Collision Handling:**

#### **1. Chaining (Linked List in Buckets)**
- Each bucket contains a linked list to store multiple key-value pairs.
- **Example:**
    ```
    Bucket 2 -> [(12, "Banana"), (22, "Cherry")]
    ```
- **Pros:** Simple and dynamic.
- **Cons:** Slower lookups if many elements are in the same bucket.

#### **2. Open Addressing**
Instead of using lists, **colliding keys are placed in another available slot** in the array.

- **Linear Probing:** Find the next available slot sequentially.
- **Quadratic Probing:** Search using `hash + i^2`.
- **Double Hashing:** Use a second hash function to rehash the index.

##### **Example of Linear Probing:**
```cpp
int findNextSlot(int hashIndex, int bucketSize) {
    return (hashIndex + 1) % bucketSize;  // Move to the next slot.
}
```
- **Pros:** Saves space.
- **Cons:** Can cause clustering, reducing efficiency.

---

## 4. Implementing a Simple HashMap in C++
### **Structure of a Basic HashMap:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

class HashMap {
    int bucketSize;
    vector<vector<pair<int, string>>> bucketArray; // Chaining with vectors

public:
    HashMap(int size) {
        bucketSize = size;
        bucketArray.resize(bucketSize);
    }

    int hashFunction(int key) {
        return key % bucketSize;
    }

    void insert(int key, string value) {
        int index = hashFunction(key);
        bucketArray[index].push_back({key, value});
    }

    string get(int key) {
        int index = hashFunction(key);
        for (auto &pair : bucketArray[index]) {
            if (pair.first == key) return pair.second;
        }
        return "Not Found";
    }
};

int main() {
    HashMap myMap(10);
    myMap.insert(12, "Banana");
    myMap.insert(22, "Cherry"); // Collision handled by chaining
    cout << "Value for key 12: " << myMap.get(12) << endl;
    cout << "Value for key 22: " << myMap.get(22) << endl;
    return 0;
}
```

---

## Summary
| Concept | Explanation |
|---------|------------|
| **Bucket Array** | Stores elements in indexed buckets. |
| **Hash Function** | Maps a key to a valid index in the bucket array. |
| **Collision Handling** | Techniques like chaining and open addressing prevent key conflicts. |
| **Chaining** | Uses linked lists to store multiple key-value pairs in the same bucket. |
| **Open Addressing** | Resolves collisions by finding the next available bucket. |
| **Implementation** | A HashMap can be implemented using arrays, vectors, or linked lists. |
