# Priority Queue, Heap, and Complete Binary Tree (CBT)

---

## 1. Priority Queue 

A **Priority Queue** is a special type of queue where every element has a priority. Unlike a normal queue (which is first-in-first-out), a priority queue always processes the element with the highest (or lowest) priority first.

### Key Points:

- **Order Based on Priority:**  
  The order in which elements are removed depends on their priority, not on the order they were added.
- **Common Uses:**  
  Used in scheduling tasks, managing processes, and graph algorithms like Dijkstra’s shortest path.

### Types of Priority Queues:

| Type                   | Description                                           | Typical Use                                   |
| ---------------------- | ----------------------------------------------------- | --------------------------------------------- |
| **Max Priority Queue** | The element with the highest value is given priority. | When highest value should be processed first. |
| **Min Priority Queue** | The element with the lowest value is given priority.  | When lowest value should be processed first.  |

_Note:_ In C++, the Standard Template Library (STL) provides a `priority_queue` which is a max priority queue by default.

---

## 2. Heap

A **Heap** is a tree-based data structure that is often used to implement a priority queue. It must follow two main rules:

1. **Heap Property:**
   - In a **Max Heap**, every parent node is greater than or equal to its children.
   - In a **Min Heap**, every parent node is less than or equal to its children.
2. **Complete Binary Tree:**  
   The heap is always a complete binary tree (explained in detail in the next section).

### Max Heap Example:

```
        [50]
       /    \
    [30]    [40]
    /  \     /  \
  [10] [20] [35] [25]
```

- **Explanation:**  
  The parent (50) is the largest element. Every parent node is larger than its children.

### Min Heap Example:

```
        [10]
       /    \
    [20]    [15]
    /  \     /  \
  [30] [25] [40] [35]
```

- **Explanation:**  
  The parent (10) is the smallest element. Every parent node is smaller than its children.

### Importance of Heaps:

- **Efficient Operations:**  
  Both insertion and deletion (especially the removal of the root) can be done in **O(log n)** time.
- **Applications:**  
  Used to implement priority queues, and also in algorithms like Heap Sort.

---

## 3. Complete Binary Tree (CBT)

A **Complete Binary Tree** is a binary tree in which:

- Every level, except possibly the last, is completely filled.
- In the last level, nodes are filled from left to right.

### Why is it Important?

- **Compact Representation:**  
  A complete binary tree can be stored in an array without any gaps.
- **Performance:**  
  This structure helps maintain efficient operations in heaps (keeping the tree balanced).

### Fully Filled Tree Example:

```
        [A]
       /    \
    [B]      [C]
    /  \    /   \
  [D]  [E] [F]   [G]
```

- **Explanation:**  
  All levels are completely filled.

### Nearly Complete Tree Example (Last Level Not Fully Filled):

```
        [A]
       /    \
    [B]      [C]
    /  \     /
  [D]  [E]  [F]
```

- **Explanation:**  
  The last level is not full, but nodes are as far left as possible.

### Comparison Table: Binary Tree Types

| Property                 | Complete Binary Tree                                                   | Full Binary Tree                       | Perfect Binary Tree                   |
| ------------------------ | ---------------------------------------------------------------------- | -------------------------------------- | ------------------------------------- |
| **Definition**           | All levels full except possibly the last; last level filled from left. | Every node has either 0 or 2 children. | All levels completely filled.         |
| **Array Representation** | Very efficient, no gaps.                                               | May have gaps if not complete.         | Most efficient, but rare in practice. |
| **Use in Heaps**         | Yes, heaps are implemented as complete binary trees.                   | Not typically used for heaps.          | Not required for heap operations.     |

---

## Summary

- **Priority Queue:**  
  A structure where each element has a priority. The element with the highest (or lowest) priority is processed first. In C++, the default `priority_queue` is a max priority queue.

- **Heap:**  
  A specialized tree used to implement priority queues. It obeys the heap property (max or min) and is always a complete binary tree, ensuring efficient operations.

- **Complete Binary Tree (CBT):**  
  A binary tree that is completely filled on all levels except possibly the last. Nodes in the last level are filled from left to right. This property makes it very efficient for array-based storage and for implementing heaps.

---
