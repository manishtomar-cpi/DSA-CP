# Inorder Traversal of Binary Tree (left, root, right)

## Introduction

Inorder traversal is a method of visiting the nodes of a binary tree in the following order:

1. Visit the left subtree.
2. Visit the root node.
3. Visit the right subtree.

This traversal is useful for extracting data from a binary search tree in sorted order.

In this document, we will discuss:

- Recursive Inorder Traversal
- Iterative Inorder Traversal

Both approaches will be explained with code, diagrams, and a comparison table.

---

## Recursive Inorder Traversal

### Algorithm

1. If the current node is `null`, return.
2. Recursively call the function for the left subtree.
3. Process (print) the current node.
4. Recursively call the function for the right subtree.

### Code

```cpp
void inorderRecursive(BTNode* root) {
    if (root == nullptr) {
        return;
    }
    // Traverse the left subtree
    inorderRecursive(root->left);
    // Visit the root node
    cout << root->data << ", ";
    // Traverse the right subtree
    inorderRecursive(root->right);
}
```

### Diagram

For a binary tree:

```
        4
       / \
      2   6
     / \
    1   3
```

The recursive calls will follow this sequence:

```
Recursive Call Stack:
1. Left of 4 (2)
2. Left of 2 (1)
3. Visit 1
4. Back to 2, visit 2
5. Right of 2 (3)
6. Visit 3
7. Back to 4, visit 4
8. Right of 4 (6)
9. Visit 6
```

### Output

```
1, 2, 3, 4, 6
```

---

## Iterative Inorder Traversal

### Algorithm

1. Create an empty stack.
2. Initialize the current node as the root.
3. While the current node is not `null` or the stack is not empty:
   - Push the current node onto the stack and move to its left child.
   - If the current node is `null`, pop a node from the stack, visit it, and move to its right child.
4. Repeat until the stack is empty and the current node is `null`.

### Code

```cpp
void inorderIterative(BTNode* root) {
    stack<BTNode*> st;
    BTNode* current = root;

    while (current != nullptr || !st.empty()) {
        // Push all left children to the stack
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }

        // Process the top node
        current = st.top();
        st.pop();
        cout << current->data << ", ";

        // Move to the right subtree
        current = current->right;
    }
}
```

### Diagram

For the same binary tree:

```
        4
       / \
      2   6
     / \
    1   3
```

The stack operation sequence:
| Stack Contents | Current Node | Action |
|-----------------|--------------|------------------|
| [4] | 2 | Push 4, Move Left|
| [4, 2] | 1 | Push 2, Move Left|
| [4, 2, 1] | null | Pop 1, Visit Node|
| [4, 2] | null | Pop 2, Visit Node|
| [4] | 3 | Push 3, Move Left|
| [4, 3] | null | Pop 3, Visit Node|
| [] | 4 | Pop 4, Visit Node|
| [] | 6 | Push 6, Move Left|
| [6] | null | Pop 6, Visit Node|

### Output

```
1, 2, 3, 4, 6
```

---

## Comparison Table

| Feature              | Recursive Approach            | Iterative Approach               |
| -------------------- | ----------------------------- | -------------------------------- |
| **Space Complexity** | O(h) (call stack)             | O(h) (explicit stack)            |
| **Time Complexity**  | O(n)                          | O(n)                             |
| **Implementation**   | Simple, shorter code          | Slightly more complex            |
| **Best Use Case**    | When recursion depth is small | When avoiding recursion overhead |

---

## Conclusion

- Recursive and iterative inorder traversals achieve the same results, but the choice depends on the specific use case.
- Recursive traversal is simpler to implement but may cause stack overflow for very deep trees.
- Iterative traversal is more memory-efficient in such cases as it avoids using the function call stack.
