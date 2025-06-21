
#  Iterative Approach

## Approach:
- We are performing an **iterative depth-first traversal** (similar to in-order traversal).
- We maintain two variables:
  - `currentSum`: to build the number along the **root-to-current path**.
  - `totalSum`: to store the **final sum** of all root-to-leaf numbers.
- **Process:**
  - As we go down the tree (left side), we **multiply `currentSum` by 10** and **add the current node's value**.
  - We **push each visited node** into the stack to remember our path.
  - When we reach a **leaf node** (no left and right child), we **add `currentSum` to `totalSum`**.
  - After visiting a node and its left subtree:
    - If it has a **right child not yet visited**, we move to the right child.
    - Else, we **backtrack** (pop from the stack) and **remove the last digit** from `currentSum` (by dividing by 10).
- We use a `lastVisited` pointer to **keep track** of whether we have already visited the right child,  
  so we know when to backtrack safely.
- This method ensures that `currentSum` **always correctly represents the number** formed along the current path.

---

## Code

```cpp
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int currentSum = 0;
        int totalSum = 0;
        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;
        
        while (current || !st.empty()) {
            // Go as left as possible, building the currentSum
            while (current) {
                currentSum = (currentSum * 10) + current->val;
                st.push(current);
                current = current->left;
            }
            
            // Look at the top node
            current = st.top();
            
            // If it's a leaf, add the path's number to totalSum
            if (!current->left && !current->right) {
                totalSum += currentSum;
            }
            
            // If right child exists and not yet visited, move to right child
            if (current->right && current->right != lastVisited) {
                current = current->right;
            } else {
                // Backtrack: pop from stack and remove last digit from currentSum
                lastVisited = current;
                st.pop();
                currentSum /= 10;
                current = nullptr; // Set to nullptr to avoid going left again
            }
        }
        
        return totalSum;
    }
};
```
