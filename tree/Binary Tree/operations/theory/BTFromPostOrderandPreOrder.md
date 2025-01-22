# Construct Binary Tree from Postorder and Inorder Traversal (Iterative Approach)

## Introduction

Constructing a binary tree using **postorder** and **inorder** traversals involves:

1. **Postorder Traversal**:
   - Defines the order in which nodes are visited: `Left → Right → Root`.
   - The last element in postorder is always the **root** of the tree.
2. **Inorder Traversal**:
   - Helps determine the structure of the left and right subtrees: `Left → Root → Right`.

### Key Idea:

- Use postorder to identify nodes as you traverse and build the tree.
- Use inorder to determine **when to switch from adding right children to adding left children**.

---

## Algorithm

### Steps to Construct the Tree

1. **Initialization**:

   - Start with the last element in `postorder` as the **root**.
   - Push the root onto a stack.
   - Use a pointer (`inOrderIndex`) starting at the **last index** of the `inorder` array.

2. **Traverse Postorder in Reverse**:

   - For each node in the reversed `postorder`:
     1. Compare the stack's top with `inOrder[inOrderIndex]`:
        - **Case 1**: If the stack's top **does not match**:
          - The current node is part of the **right subtree**.
          - Attach it as the **right child** of the last node in the stack and push it onto the stack.
        - **Case 2**: If the stack's top **matches**:
          - The left subtree needs to be processed.
          - Pop nodes from the stack until the top no longer matches.
          - Attach the current node as the **left child** of the last popped node and push it onto the stack.

3. **Repeat**:
   - Continue until all nodes in `postorder` are processed.

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
    BTNode* makeTree(vector<int> postOrder, vector<int> inOrder) {
        stack<BTNode*> childs;
        root = new BTNode(postOrder[postOrder.size() - 1]); // The last element in postorder is the root
        childs.push(root);

        int inOrderIndex = inOrder.size() - 1; // Start from the last index of inorder

        for (int i = postOrder.size() - 2; i >= 0; i--) {
            BTNode* current = childs.top();

            if (current->data != inOrder[inOrderIndex]) {
                // Add as right child
                BTNode* rightChild = new BTNode(postOrder[i]);
                current->right = rightChild;
                childs.push(rightChild);
            } else {
                // Process left child
                while (!childs.empty() && childs.top()->data == inOrder[inOrderIndex]) {
                    current = childs.top();
                    childs.pop();
                    inOrderIndex--;
                }
                BTNode* leftChild = new BTNode(postOrder[i]);
                current->left = leftChild;
                childs.push(leftChild);
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
    vector<int> postOrder = {9, 15, 7, 20, 3}; // Postorder Traversal
    vector<int> inOrder = {9, 3, 15, 20, 7};   // Inorder Traversal

    bt.makeTree(postOrder, inOrder);
    bt.print();

    return 0;
}
```

---

## Example Walkthrough

### Input:

- Postorder: `{9, 15, 7, 20, 3}`
- Inorder: `{9, 3, 15, 20, 7}`

---

### Execution Steps:

#### Step 1: Initialization

- Root node is created from the last element in `postorder`:
  - Root = `3`.
- Push `3` onto the stack.

---

#### Step 2: Process `20` (Next in `postorder`)

- Compare `stack.top()` (i.e., `3`) with `inOrder[inOrderIndex]` (i.e., `7`):
  - `3 != 7` → Add `20` as the **right child** of `3`.
  - Push `20` onto the stack.

---

#### Step 3: Process `7` (Next in `postorder`)

- Compare `stack.top()` (i.e., `20`) with `inOrder[inOrderIndex]` (i.e., `7`):
  - `20 != 7` → Add `7` as the **right child** of `20`.
  - Push `7` onto the stack.

---

#### Step 4: Process `15` (Next in `postorder`)

- Compare `stack.top()` (i.e., `7`) with `inOrder[inOrderIndex]` (i.e., `7`):
  - `7 == 7` → Pop `7` and move `inOrderIndex` to `3`.
- Compare `stack.top()` (i.e., `20`) with `inOrder[inOrderIndex]` (i.e., `20`):
  - `20 == 20` → Pop `20` and move `inOrderIndex` to `2`.
- Add `15` as the **left child** of `20`.
- Push `15` onto the stack.

---

#### Step 5: Process `9` (Next in `postorder`)

- Compare `stack.top()` (i.e., `15`) with `inOrder[inOrderIndex]` (i.e., `15`):
  - `15 == 15` → Pop `15` and move `inOrderIndex` to `1`.
- Compare `stack.top()` (i.e., `3`) with `inOrder[inOrderIndex]` (i.e., `3`):
  - `3 == 3` → Pop `3` and move `inOrderIndex` to `0`.
- Add `9` as the **left child** of `3`.
- Push `9` onto the stack.

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

1. **Postorder Guides Node Creation**:
   - Postorder determines which node to create next.
2. **Inorder Determines Tree Structure**:
   - Inorder helps decide when to stop adding right children and start adding left children.
3. **Stack Helps Track Nodes**:
   - The stack ensures that nodes are revisited to attach their left children.

```

```
