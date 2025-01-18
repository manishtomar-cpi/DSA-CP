# Level Order Traversal (Level by Level)

## Introduction
Level order traversal (level by level) is a method of visiting nodes of a binary tree such that nodes at each level are printed separately. This provides a clear representation of the tree structure.

---

## Algorithm
1. Create an empty queue.
2. Enqueue the root node and a `nullptr` marker to indicate the end of the first level.
3. While the queue is not empty:
    - Dequeue the front node.
    - If the dequeued node is `nullptr`:
        - Print a newline to move to the next level.
        - If the queue is not empty, enqueue another `nullptr` marker.
    - Otherwise, process the node and enqueue its children.

---

## Code
```cpp
void levelOrderTraversal()
{
    queue<BTNode *> childs;
    childs.push(root);
    childs.push(nullptr); // Marker for level separation

    while (!childs.empty())
    {
        BTNode *current = childs.front();
        childs.pop();

        if (current == nullptr)
        {
            cout << endl; // End of current level

            if (!childs.empty())
            {
                childs.push(nullptr); // Add marker for next level
            }
        }
        else
        {
            cout << current->data << " ";

            if (current->left)
            {
                childs.push(current->left);
            }
            if (current->right)
            {
                childs.push(current->right);
            }
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
The traversal will visit nodes level by level:
```
Queue Operation Sequence:
1. Enqueue 4 and `nullptr`.
2. Dequeue 4, enqueue 2 and 6.
3. Dequeue `nullptr`, enqueue another `nullptr`.
4. Dequeue 2, enqueue 1 and 3.
5. Dequeue 6 (no children to enqueue).
6. Dequeue `nullptr`, enqueue another `nullptr`.
7. Dequeue 1 and 3 (no children to enqueue).
```

---

## Output
```
4
2 6
1 3
```

---

## Key Features
- **Space Complexity**: O(n), where `n` is the number of nodes (queue size includes nodes and level markers).
- **Time Complexity**: O(n), as every node is processed exactly once.
- **Output Format**: Hierarchical, showing nodes level by level.

---

## Conclusion
Level order traversal with levels printed separately is an effective way to visualize the hierarchical structure of a binary tree. It is particularly useful when understanding the tree's layout or debugging level-specific logic.
