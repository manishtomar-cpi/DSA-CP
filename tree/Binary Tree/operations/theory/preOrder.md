# Binary Tree Traversals

## Preorder Traversal (Root, Left, Right)

### Introduction

Preorder traversal is a method of visiting the nodes of a binary tree in the following order:

1. Visit the root node.
2. Traverse the left subtree.
3. Traverse the right subtree.

This traversal is often used when you want to copy a tree or evaluate expressions stored in a binary tree.

---

## Algorithm (Iterative Approach)

1. Create an empty stack.
2. Push the root node onto the stack.
3. While the stack is not empty:
   - Pop the top node and process it.
   - If the popped node has a right child, push it onto the stack.
   - If the popped node has a left child, push it onto the stack.

This ensures that the left subtree is processed before the right subtree.

---

## Code

```cpp
/*
D, L, R is the order (Data, Left, Right)
STEP-1: Push the root into the stack.
STEP-2: Make the current node the top of the stack, then pop the stack and process the node.
STEP-3: Check for the right subtree first; if it exists, push it onto the stack. Then check for the left subtree and push it onto the stack.
STEP-4: Repeat steps 2 and 3 until the stack is empty.
*/

void getPreorder()
{
    stack<BTNode *> childs;
    // Step 1
    childs.push(root);
    while (!childs.empty()) // Step 4
    {
        // Step 2
        BTNode *current = childs.top();
        childs.pop();
        cout << current->data << ", ";

        // Step 3
        if (current->right)
        {
            childs.push(current->right);
        }
        if (current->left)
        {
            childs.push(current->left);
        }
    }
}
```

---

## Diagram

For the binary tree:

```
        4
       / \
      2   6
     / \
    1   3
```

The traversal will visit nodes in the following order:

```
Preorder Sequence:
4, 2, 1, 3, 6

Stack Operation Sequence:
1. Push 4 (root).
2. Pop 4, process it, push 6 and 2.
3. Pop 2, process it, push 3 and 1.
4. Pop 1, process it (no children to push).
5. Pop 3, process it (no children to push).
6. Pop 6, process it (no children to push).
```

---

## Output

```
4, 2, 1, 3, 6
```

---

## Key Features

- **Space Complexity**: O(h), where `h` is the height of the tree (stack size).
- **Time Complexity**: O(n), where `n` is the number of nodes.
- **Traversal Order**: Root, Left, Right.

---

## Conclusion

Preorder traversal is efficient for scenarios where you need to process the root node before its subtrees. The iterative approach uses a stack to simulate the recursive process, ensuring the correct traversal order without recursion.
