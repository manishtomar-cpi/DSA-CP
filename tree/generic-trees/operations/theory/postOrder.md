# Post-order Traversal in Trees

Post-order traversal is a tree traversal technique where the nodes are visited in the following order:

1. **Traverse the left subtree recursively.**
2. **Traverse the right subtree recursively.**
3. **Visit the root node.**

This traversal ensures that the children of a node are processed before the node itself. It is commonly used for:
- Deleting nodes in a tree.
- Evaluating postfix expressions.
- Calculating space occupied by a directory and its subdirectories.

## Recursive Post-order Traversal
### Algorithm
The recursive approach to post-order traversal involves:
1. Traversing each child recursively.
2. Visiting the current node after all children are processed.

**Code Implementation:**
```cpp
void postOrderTraversal(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    for (int i = 0; i < root->childrens.size(); i++) {
        postOrderTraversal(root->childrens[i]);
    }
    cout << root->data << ", ";
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
postOrderTraversal(1)
  |
  +-- postOrderTraversal(2)
  |      |
  |      +-- postOrderTraversal(5)
  |      +-- postOrderTraversal(6)
  |
  +-- postOrderTraversal(3)
  |
  +-- postOrderTraversal(4)
         |
         +-- postOrderTraversal(7)
```

#### Output
```
5, 6, 2, 3, 7, 4, 1,
```

### Key Insights
- The function stack implicitly manages the traversal sequence.
- Each node processes its children before being visited itself.

## Iterative Post-order Traversal
### Algorithm
The iterative approach to post-order traversal involves:
1. Using two stacks: one to traverse the tree (`s1`) and the other to store the post-order sequence (`s2`).
2. Pushing the root node into the first stack.
3. Repeatedly processing nodes from the first stack, pushing them into the second stack, and adding their children to the first stack.
4. Popping nodes from the second stack to obtain the post-order sequence.

**Code Implementation:**
```cpp
void postOrderTraversalIterative(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode *> s1; // For traversal
    stack<TreeNode *> s2; // For post-order sequence

    // Push the root node into the first stack
    s1.push(root);

    while (!s1.empty()) {
        TreeNode *current = s1.top();
        s1.pop();
        s2.push(current);

        for (int i = 0; i < current->childrens.size(); i++) {
            s1.push(current->childrens[i]);
        }
    }

    while (!s2.empty()) {
        cout << s2.top()->data << ", ";
        s2.pop();
    }
    cout << endl;
}
```

### Example
Using the same tree:

#### Stack Operations
| **Stack 1 (Traversal)** | **Stack 2 (Post-order)** | **Current Node** | **Output** |
|-------------------------|--------------------------|------------------|------------|
| [1]                    | []                       | 1                | -          |
| [2, 3, 4]              | [1]                     | 4                | -          |
| [2, 3, 7]              | [1, 4]                  | 7                | -          |
| [2, 3]                 | [1, 4, 7]               | 3                | -          |
| [2]                    | [1, 4, 7, 3]            | 2                | -          |
| [5, 6]                 | [1, 4, 7, 3, 2]         | 6                | -          |
| [5]                    | [1, 4, 7, 3, 2, 6]      | 5                | -          |
| []                     | [1, 4, 7, 3, 2, 6, 5]   | -                | -          |

#### Output Sequence
```
5, 6, 2, 3, 7, 4, 1,
```

### Visualization
The stack simulation for this example is illustrated as:

```
Initial: s1 = [1], s2 = []
Step 1: s1 = [2, 3, 4], s2 = [1]
Step 2: s1 = [2, 3, 7], s2 = [1, 4]
Step 3: s1 = [2, 3], s2 = [1, 4, 7]
...
```

### Key Insights
- The two stacks explicitly manage the traversal and storage sequences.
- The final output is obtained by processing nodes from the second stack.

## Comparison
| **Aspect**                | **Recursive**         | **Iterative**         |
|---------------------------|-----------------------|-----------------------|
| Space Complexity          | O(h) (call stack)    | O(2h) (two stacks)   |
| Ease of Implementation    | Simple               | Moderate              |
| Flexibility               | Less flexible        | More flexible         |

Where `h` is the height of the tree.

### Summary
Both recursive and iterative methods of post-order traversal are effective. The iterative approach may be preferred in cases where recursion depth is a concern or where explicit control of the traversal process is required.

