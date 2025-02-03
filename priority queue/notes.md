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

## Implementation of Priority Queue

A priority queue can be implemented using various data structures. Below is a comparison of different implementations based on **Insertion, Deletion, and Finding Min/Max**.

| Data Structure                        | Insert   | Delete (Min/Max) | Get Min/Max | Space Complexity |
| ------------------------------------- | -------- | ---------------- | ----------- | ---------------- |
| **Unsorted Array**                    | O(1)     | O(n)             | O(n)        | O(n)             |
| **Sorted Array**                      | O(n)     | O(1)             | O(1)        | O(n)             |
| **Unsorted Linked List**              | O(1)     | O(n)             | O(n)        | O(n)             |
| **Sorted Linked List**                | O(n)     | O(1)             | O(1)        | O(n)             |
| **Binary Search Tree (BST)**          | O(log n) | O(log n)         | O(log n)    | O(n)             |
| **Balanced BST (AVL/Red-Black Tree)** | O(log n) | O(log n)         | O(log n)    | O(n)             |
| **Heap (Binary Heap - Min/Max)**      | O(log n) | O(log n)         | O(1)        | O(n)             |

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

  ## 3. Insert and Delete Operations in Heaps

### Insertion in a Heap

Insertion in a heap follows these steps:

1. **Insert the element at the next available position** in the heap (to maintain CBT properties).
2. **Heapify Up (Bubble Up):**
   - Compare the inserted node with its parent.
   - If the heap property is violated, swap with the parent.
   - Repeat this process until the heap property is restored.

#### Example: Insert `45` in a Max Heap

```
Before insertion:
        [50]
       /    \
    [30]    [40]
    /  \     /  \
  [10] [20] [35] [25]
```

After inserting `45` at the next available position (as the left child of `10`):

```
        [50]
       /    \
    [30]    [40]
    /  \     /  \
  [10] [20] [35] [25]
  /
[45]
```

**Heapify Up Process:**

1. `45` is greater than its parent `10`, so swap them.

```
        [50]
       /    \
    [30]    [40]
    /  \     /  \
  [45] [20] [35] [25]
  /
[10]
```

2. `45` is greater than `30`, so swap them.

```
        [50]
       /    \
    [45]    [40]
    /  \     /  \
  [30] [20] [35] [25]
  /
[10]
```

3. `45` is still smaller than `50`, so no further swaps are needed.

**Final Max Heap:**

```
        [50]
       /    \
    [45]    [40]
    /  \     /  \
  [30] [20] [35] [25]
  /
[10]
```

**Time Complexity:** `O(log n)`, as the node moves up at most `log n` levels.

---

### Deletion in a Heap

1. **Remove the root element** (highest priority in a max heap, lowest in a min heap).
2. **Replace the root with the last element** to maintain CBT properties.
3. **Heapify Down (Bubble Down):**
   - Compare the new root with its children.
   - If the heap property is violated, swap with the larger child (max heap) or smaller child (min heap).
   - Repeat until the heap property is restored.

#### Example: Delete `50` from the Max Heap

```
Before deletion:
        [50]
       /    \
    [45]    [40]
    /  \     /  \
  [30] [20] [35] [25]
  /
[10]

Step 1: Replace `50` with `10`
        [10]
       /    \
    [45]    [40]
    /  \     /  \
  [30] [20] [35] [25]

Step 2: Heapify Down (swap `10` with `45`)
        [45]
       /    \
    [10]    [40]
    /  \     /  \
  [30] [20] [35] [25]

Step 3: Heapify Down (swap `10` with `30`)
        [45]
       /    \
    [30]    [40]
    /  \     /  \
  [10] [20] [35] [25]
```

Final Max Heap after deletion:

```
        [45]
       /    \
    [30]    [40]
    /  \     /  \
  [10] [20] [35] [25]
```

**Time Complexity:** `O(log n)`, as the node moves down at most `log n` levels.

---

## Summary

- **Insertion in a Heap:** Always inserts at the last position and restores the heap property using **Heapify Up**.
- **Deletion in a Heap:** Always removes the root, replaces it with the last node, and restores the heap using **Heapify Down**.
- **Time Complexity:** Both insertion and deletion operate in `O(log n)` time complexity due to heapifying.

---

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

### Array Representation of CBT

A complete binary tree can be efficiently represented using an array. The position of each node is determined by its index in the array:

- **Parent of node at index `i`** → Located at index `(i - 1) / 2`
- **Left child of node at index `i`** → Located at index `2i + 1`
- **Right child of node at index `i`** → Located at index `2i + 2`

#### Example:

```
Index:  0   1   2   3   4   5   6
Array: [A] [B] [C] [D] [E] [F] [G]
```

- `A` (index `0`) has children `B` (index `1`) and `C` (index `2`).
- `B` (index `1`) has children `D` (index `3`) and `E` (index `4`).
- `C` (index `2`) has children `F` (index `5`) and `G` (index `6`).

```
Index:  0   1   2   3   4   5   6
Array: [A] [B] [C] [D] [E] [F] [G]
```

- **Proof of Parent Formula (`(i-1)/2`)**:

  - For `D` (Index `3`): Parent index = `(3-1)/2 = 1` → `B` (Correct!)
  - For `E` (Index `4`): Parent index = `(4-1)/2 = 1` → `B` (Correct!)
  - For `F` (Index `5`): Parent index = `(5-1)/2 = 2` → `C` (Correct!)

- **Proof of Left Child Formula (`2i+1`)**:

  - For `A` (Index `0`): Left child index = `2(0)+1 = 1` → `B` (Correct!)
  - For `B` (Index `1`): Left child index = `2(1)+1 = 3` → `D` (Correct!)

- **Proof of Right Child Formula (`2i+2`)**:
  - For `A` (Index `0`): Right child index = `2(0)+2 = 2` → `C` (Correct!)
  - For `B` (Index `1`): Right child index = `2(1)+2 = 4` → `E` (Correct!)

### Insertion in CBT

Insertion into a CBT is always done at the leftmost available position at the last level to maintain completeness.

- **Steps for insertion:**
  1. Place the new node at the next available index in the array.
  2. If needed, adjust the heap property (swap with parent if necessary).

**Time Complexity:** `O(1)` for insertion in an array representation.

### Deletion in CBT

Deletion from a CBT typically removes the **last inserted node** to maintain completeness.

- **Steps for deletion:**
  1. Replace the root node with the last node in the array.
  2. Remove the last node.
  3. Adjust the heap property by swapping downwards (heapify).

**Time Complexity:** `O(1)` for deleting the last node, `O(log n)` for heapify adjustments.

---

## Summary

- **Priority Queue:**  
  A structure where each element has a priority. The element with the highest (or lowest) priority is processed first. In C++, the default `priority_queue` is a max priority queue.

- **Heap:**  
  A specialized tree used to implement priority queues. It obeys the heap property (max or min) and is always a complete binary tree, ensuring efficient operations.

- **Complete Binary Tree (CBT):**  
  A binary tree that is completely filled on all levels except possibly the last. Nodes in the last level are filled from left to right. This property makes it very efficient for array-based storage and for implementing heaps.

- **Insertion and Deletion in CBT:**
  - Insertions occur at the leftmost available position in the last level, ensuring `O(1)` complexity.
  - Deletions involve replacing the root with the last node and heapifying, ensuring `O(log n)` complexity for heap adjustments.

---
