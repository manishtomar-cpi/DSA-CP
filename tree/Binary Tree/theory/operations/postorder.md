## Postorder Traversal (Left, Right, Root)

### Introduction
Postorder traversal visits the nodes of a binary tree in the following order:
1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the root node.

This traversal is useful for deleting a tree or evaluating postfix expressions stored in a binary tree.

---

## Algorithm (Iterative Approach)
1. Create two empty stacks: `childs` and `result`.
2. Push the root node onto the `childs` stack.
3. While the `childs` stack is not empty:
    - Pop the top node from `childs` and push it onto `result`.
    - If the popped node has a left child, push it onto `childs`.
    - If the popped node has a right child, push it onto `childs`.
4. Once the `childs` stack is empty, pop all nodes from the `result` stack and process them.

---

## Code
```cpp
/*
L, R, D is the order (Left, Right, Data)
STEP-1: Create two stacks, one for traversal (`childs`) and one for the postorder (`result`).
STEP-2: Push the root into the `childs` stack.
STEP-3: Pop the top of `childs` and push it into `result`.
STEP-4: Push the left and right children of the popped node into `childs` (if they exist).
STEP-5: Repeat steps 3 and 4 until `childs` is empty.
STEP-6: Process the nodes in `result` for the final postorder traversal.
*/

void getPostOrder()
{
    // Step 1
    stack<BTNode *> childs;
    stack<BTNode *> result;

    // Step 2
    childs.push(root);

    while (!childs.empty()) // Step 5
    {
        BTNode *current = childs.top();
        // Step 3
        childs.pop();
        result.push(current);

        // Step 4
        if (current->left)
        {
            childs.push(current->left);
        }
        if (current->right)
        {
            childs.push(current->right);
        }
    }

    while (!result.empty()) // Step 6
    {
        cout << result.top()->data << ", ";
        result.pop();
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
Postorder Sequence:
1, 3, 2, 6, 4

Stack Operation Sequence:
1. Push 4 into `childs`.
2. Pop 4 from `childs`, push it to `result`, push 2 and 6 to `childs`.
3. Pop 6 from `childs`, push it to `result` (no children to push).
4. Pop 2 from `childs`, push it to `result`, push 1 and 3 to `childs`.
5. Pop 3 from `childs`, push it to `result` (no children to push).
6. Pop 1 from `childs`, push it to `result` (no children to push).
7. Pop all nodes from `result` in reverse order to get the postorder sequence.
```

---

## Output
```
1, 3, 2, 6, 4
```

---

## Key Features
- **Space Complexity**: O(2h), where `h` is the height of the tree (due to two stacks).
- **Time Complexity**: O(n), where `n` is the number of nodes.
- **Traversal Order**: Left, Right, Root.

---

## Conclusion
Postorder traversal is particularly useful when processing child nodes before the root, such as when deleting a tree. The iterative approach with two stacks ensures correct traversal without recursion.
