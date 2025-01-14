# Pre-order Traversal in Trees

Pre-order traversal is a tree traversal technique where the nodes are visited in the following order:

1. **Visit the root node.**
2. **Traverse the left subtree recursively.**
3. **Traverse the right subtree recursively.**

This traversal technique ensures that the root is always processed before its children, making it suitable for applications such as:
- Expression tree evaluation.
- Cloning or copying a tree.
- Serializing and deserializing trees for storage or transmission.

## Recursive Pre-order Traversal
### Algorithm
The recursive approach to pre-order traversal involves:
1. Visiting the current node.
2. Recursively traversing each child.

**Code Implementation:**
```cpp
void preOrderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << ", ";
    for (int i = 0; i < root->childrens.size(); i++) {
        preOrderTraversal(root->childrens[i]);
    }
}
```

### Example
Consider the following tree:

```
        1
      / | \
     2  3  4
    / \    /
   5   6  7
```

#### Recursion Tree
The recursion tree for this example is shown below:

```
preOrderTraversal(1)
  |
  +-- preOrderTraversal(2)
  |      |
  |      +-- preOrderTraversal(5)
  |      +-- preOrderTraversal(6)
  |
  +-- preOrderTraversal(3)
  |
  +-- preOrderTraversal(4)
         |
         +-- preOrderTraversal(7)
```

#### Output
```
1, 2, 5, 6, 3, 4, 7,
```

### Key Insights
- The function stack implicitly manages the traversal sequence.
- Each node processes its children recursively before the parent completes execution.

## Iterative Pre-order Traversal
### Algorithm
The iterative approach to pre-order traversal involves:
1. Using a stack to simulate the recursion.
2. Pushing the root node onto the stack.
3. Repeatedly processing the stack by popping a node, visiting it, and pushing its children in reverse order.

**Code Implementation:**
```cpp
void preOrderTraversalIterative(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode *> childs;
    childs.push(root);

    while (!childs.empty()) {
        TreeNode *current = childs.top();
        childs.pop();
        cout << current->data << ", ";

        for (int i = current->childrens.size() - 1; i >= 0; i--) {
            childs.push(current->childrens[i]);
        }
    }
    cout << endl;
}
```

### Example
Using the same tree:

#### Stack Operations
| **Stack State**         | **Current Node** | **Output** |
|-------------------------|------------------|------------|
| [1]                    | 1                | 1          |
| [4, 3, 2]              | 2                | 1, 2       |
| [4, 3, 6, 5]           | 5                | 1, 2, 5    |
| [4, 3, 6]              | 6                | 1, 2, 5, 6 |
| [4, 3]                 | 3                | 1, 2, 5, 6, 3 |
| [4]                    | 4                | 1, 2, 5, 6, 3, 4 |
| [7]                    | 7                | 1, 2, 5, 6, 3, 4, 7 |
| []                     | -                | Complete   |

#### Visualization
The stack simulation for this example is illustrated as:

```
Initial: Stack = [1]
Step 1: Stack = [4, 3, 2], Output = 1
Step 2: Stack = [4, 3, 6, 5], Output = 1, 2
Step 3: Stack = [4, 3, 6], Output = 1, 2, 5
Step 4: Stack = [4, 3], Output = 1, 2, 5, 6
...
```

### Key Insights
- The stack explicitly manages the traversal sequence.
- Children are processed in reverse order to ensure correct output order.

## Comparison
| **Aspect**                | **Recursive**         | **Iterative**         |
|---------------------------|-----------------------|-----------------------|
| Space Complexity          | O(h) (call stack)    | O(h) (explicit stack) |
| Ease of Implementation    | Simple               | Moderate              |
| Flexibility               | Less flexible        | More flexible         |

Where `h` is the height of the tree.

### Summary
Both recursive and iterative methods of pre-order traversal are effective, with the choice depending on specific constraints or requirements like avoiding stack overflow or utilizing explicit stack manipulation.

