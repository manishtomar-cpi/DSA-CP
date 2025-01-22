# Construct Binary Tree from Preorder and Inorder Traversal (Iterative Approach)

## Introduction

Constructing a binary tree using **preorder** and **inorder** traversals involves using:

1. **Preorder Traversal**:
   - Defines the order in which nodes are visited: `Root → Left → Right`.
   - The first element in preorder is always the **root** of the tree.
2. **Inorder Traversal**:
   - Helps determine the structure of the left and right subtrees: `Left → Root → Right`.

### Key Idea:

- Use preorder to identify nodes as you traverse and build the tree.
- Use inorder to determine **when to switch from adding left children to adding right children**.

---

## Algorithm

### Steps to Construct the Tree

1. **Initialization**:

   - Start with the first element of `preorder` as the root.
   - Push the root onto a stack.
   - Use a pointer (`inOrderIndex`) to track the current position in the `inorder` array.

2. **Process Each Node**:

   - For each element in `preorder`:
     1. Compare the stack's top with the current value in `inorder`:
        - **Case 1**: If the stack's top **does not match** the `inorder` value:
          - The current node is the **left child** of the top node.
          - Create the node, attach it as the left child, and push it onto the stack.
        - **Case 2**: If the stack's top **matches** the `inorder` value:
          - Pop nodes from the stack until the top no longer matches.
          - Move `inOrderIndex` forward for each popped node.
          - The current node is the **right child** of the last popped node.
          - Push the current node onto the stack.

3. **Repeat**:
   - Continue this process until all nodes in `preorder` are processed.

---

## Code

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class BTNode {
private:
    BTNode* root;
    BTNode* left;
    BTNode* right;
    int data;

public:
    BTNode(int val) : data(val), root(nullptr), left(nullptr), right(nullptr) {}
    BTNode() : root(nullptr), left(nullptr), right(nullptr) {}

    // Function to construct the tree
    BTNode* makeTree(vector<int> preOrder, vector<int> inOrder) {
        stack<BTNode*> nodes;
        int inOrderIndex = 0;
        root = new BTNode(preOrder[0]); // The first element in preorder is the root
        nodes.push(root);

        for (int i = 1; i < preOrder.size(); i++) {
            BTNode* current = nodes.top();

            if (current->data != inOrder[inOrderIndex]) {
                // Add as left child
                BTNode* leftNode = new BTNode(preOrder[i]);
                current->left = leftNode;
                nodes.push(leftNode);
            } else {
                // Process right child
                while (!nodes.empty() && nodes.top()->data == inOrder[inOrderIndex]) {
                    current = nodes.top();
                    nodes.pop();
                    inOrderIndex++;
                }
                BTNode* rightNode = new BTNode(preOrder[i]);
                current->right = rightNode;
                nodes.push(rightNode);
            }
        }
        return root;
    }

    // Function to print the tree (Level Order Traversal)
    void print() {
        if (!root) return;

        queue<BTNode*> q;
        q.push(root);

        while (!q.empty()) {
            BTNode* current = q.front();
            q.pop();

            cout << current->data << ": ";
            if (current->left) {
                cout << "L" << current->left->data << ", ";
                q.push(current->left);
            }
            if (current->right) {
                cout << "R" << current->right->data << ", ";
                q.push(current->right);
            }
            cout << endl;
        }
    }
};

int main() {
    BTNode bt;
    vector<int> preOrder = {3, 9, 20, 15, 7}; // Preorder Traversal
    vector<int> inOrder = {9, 3, 15, 20, 7};  // Inorder Traversal

    bt.makeTree(preOrder, inOrder);
    bt.print();

    return 0;
}
```

---

## Example Walkthrough

### Input:

- Preorder: `{3, 9, 20, 15, 7}`
- Inorder: `{9, 3, 15, 20, 7}`

### Execution Steps:

#### Step 1: Initialization

- Root node is created from the first element in `preorder`:
  - Root = `3`.
- Push `3` onto the stack.

#### Step 2: Process `9` (Next in `preorder`)

- Compare `stack.top()` (i.e., `3`) with `inOrder[inOrderIndex]` (i.e., `9`):
  - `3 != 9` → Add `9` as the **left child** of `3`.
  - Push `9` onto the stack.

---

#### Step 3: Process `20` (Next in `preorder`)

- Compare `stack.top()` (i.e., `9`) with `inOrder[inOrderIndex]` (i.e., `9`):
  - `9 == 9` → Pop `9` from the stack and move `inOrderIndex` forward.
- Compare `stack.top()` (i.e., `3`) with `inOrder[inOrderIndex]` (i.e., `3`):
  - `3 == 3` → Pop `3` from the stack and move `inOrderIndex` forward.
- Add `20` as the **right child** of `3`.
- Push `20` onto the stack.

---

#### Step 4: Process `15` (Next in `preorder`)

- Compare `stack.top()` (i.e., `20`) with `inOrder[inOrderIndex]` (i.e., `15`):
  - `20 != 15` → Add `15` as the **left child** of `20`.
  - Push `15` onto the stack.

---

#### Step 5: Process `7` (Next in `preorder`)

- Compare `stack.top()` (i.e., `15`) with `inOrder[inOrderIndex]` (i.e., `15`):
  - `15 == 15` → Pop `15` from the stack and move `inOrderIndex` forward.
- Compare `stack.top()` (i.e., `20`) with `inOrder[inOrderIndex]` (i.e., `20`):
  - `20 == 20` → Pop `20` from the stack and move `inOrderIndex` forward.
- Add `7` as the **right child** of `20`.
- Push `7` onto the stack.

---

### Final Tree:

```
        3
       / \
      9   20
         /  \
        15   7
```

---

### Output:

```
3: L9, R20,
9:
20: L15, R7,
15:
7:
```

---

## Complexity Analysis

### Time Complexity:

- **Building the Tree**: \(O(n)\)
  - Each node is pushed and popped from the stack once.
- **Printing the Tree**: \(O(n)\)
  - Each node is visited once in level-order traversal.

### Space Complexity:

- **Stack**: \(O(h)\), where \(h\) is the height of the tree.
- **Unordered Map**: \(O(n)\), where \(n\) is the number of nodes in the tree.

---

## Key Insights

1. **Preorder Guides Node Creation**:
   - Preorder determines which node to create next.
2. **Inorder Determines Tree Structure**:
   - Inorder helps decide when to stop adding left children and start adding right children.
3. **Stack Helps Track Nodes**:
   - The stack ensures that nodes are revisited to attach their right children.

```

```
