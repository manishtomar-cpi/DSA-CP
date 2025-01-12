# Comprehensive Guide to Trees in Data Structures

## Table of Contents

1. **Introduction to Trees**
2. **Key Terminologies in Trees**
3. **Types of Trees**
4. **Operations on Trees**
5. **Implementation of Tree Operations**
6. **Creating a Tree Level-Wise**
7. **Printing Trees**
8. **Tables and Diagrams**
9. **Conclusion**

---

## 1. Introduction to Trees

A **tree** is a hierarchical data structure that simulates a tree-like structure with nodes connected by edges. Trees are widely used in various applications, including databases, file systems, and networking.

### Characteristics of a Tree:
- **Non-linear data structure:** Unlike arrays or linked lists, trees represent hierarchical relationships.
- **Rooted structure:** Each tree has a root node as the topmost element.
- **Acyclic nature:** There are no cycles in a tree.

---

## 2. Key Terminologies in Trees

### Node:
A basic unit of a tree containing data. Each node may have child nodes.

### Root:
The topmost node of a tree. It is the ancestor of all other nodes.

### Edge:
The connection between two nodes in a tree.

### Parent:
A node that has one or more child nodes.

### Child:
A node that has a parent node.

### Siblings:
Nodes that share the same parent.

### Leaf Node:
A node that has no children.

### Height of a Tree:
The longest path from the root to a leaf node.

### Depth of a Node:
The distance from the root node to the given node.

### Degree:
The number of children a node has.

### Subtree:
A tree formed by a node and its descendants.

---

## 3. Types of Trees

### General Tree:
A tree where a node can have any number of children.

### Binary Tree:
A tree where each node has at most two children (left and right).

### Binary Search Tree:
A binary tree where the left subtree contains nodes with values less than the root, and the right subtree contains nodes with values greater than the root.

### Balanced Tree:
A tree where the height difference between the left and right subtrees of any node is at most one.

### Complete Tree:
A binary tree in which all levels are completely filled except possibly the last, which is filled from left to right.

---

## 4. Operations on Trees

### Common Operations:
1. **Traversal:** Visiting all the nodes of the tree (e.g., Pre-order, In-order, Post-order).
2. **Insertion:** Adding a new node.
3. **Deletion:** Removing a node.
4. **Search:** Finding a node in the tree.
5. **Level-Wise Traversal:** Visiting nodes level by level.

---

## 5. Implementation of Tree Operations

### Creating a Tree Level-Wise
This method creates a tree by:
- Taking input for the root.
- Using a queue to iteratively create and connect child nodes to their respective parents.

### Printing a Tree:
Two methods are commonly used:
1. **Recursive Print:** Prints the root and recursively traverses children.
2. **Level-Wise Print:** Uses a queue to print nodes level by level.

---

## 6. Creating a Tree Level-Wise

### Algorithm Steps:
1. Input the root node data.
2. Create a root node and add it to a queue.
3. While the queue is not empty:
   - Dequeue a node.
   - Input the number of children for the node.
   - For each child:
     - Create a child node.
     - Add the child node to the current node’s children.
     - Enqueue the child node.

### Code Example:
```cpp
TreeNode *makeTreeLevelWise() {
    queue<TreeNode *> nodes;
    int rootData;
    cin >> rootData;
    root = new TreeNode(rootData);
    nodes.push(root);

    while (!nodes.empty()) {
        TreeNode *temp = nodes.front();
        nodes.pop();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int childData;
            cin >> childData;
            TreeNode *child = new TreeNode(childData);
            nodes.push(child);
            temp->children.push_back(child);
        }
    }

    return root;
}
```

---

## 7. Printing Trees

### Recursive Printing:
Prints the data of a node and recursively prints its children.

### Level-Wise Printing:
Prints nodes using a queue to ensure level order traversal.

### Code Example:
```cpp
void printTree(TreeNode *root) {
    if (!root) return;
    cout << root->data << ": ";
    for (auto child : root->children)
        cout << child->data << ", ";
    cout << endl;
    for (auto child : root->children)
        printTree(child);
}
```

```cpp
void printTreeLevelWise() {
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        cout << nodes.front()->data << ": ";
        for (auto child : nodes.front()->children) {
            cout << child->data << ", ";
            nodes.push(child);
        }
        nodes.pop();
        cout << endl;
    }
}
```

---

## 8. Tables and Diagrams

### Tree Example:
#### Input:
```
Root Data: 1
Number of children of 1: 2
Child 1: 2
Child 2: 3
Number of children of 2: 1
Child 1: 4
Number of children of 3: 0
Number of children of 4: 0
```

#### Visualization:
```
        1
       / \
      2   3
     /
    4
```

### Process Table:
| Step | Queue State | Operation            | Output |
|------|-------------|----------------------|--------|
| 1    | [1]         | Process root node   | 1:     |
| 2    | [2, 3]      | Add children (2, 3) | 1: 2, 3|
| 3    | [3, 4]      | Process node 2      | 2: 4   |
| 4    | [4]         | Process node 3      | 3:     |
| 5    | []          | Process node 4      | 4:     |

---


