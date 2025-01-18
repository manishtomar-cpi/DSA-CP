Traversing the tree level wise means all nodes of the that level then come to the next level

```cpp
        while (!childs.empty())
        {
            int levelSize = childs.size(); // current size of level
            for (int i = 0; i < levelSize; i++)
            {
                BTNode *current = childs.front();
                childs.pop();
                // traverse all the nodes of current level
                if (current->left)
                {
                    childs.push(current->left);
                }
                if (current->right)
                {
                    childs.push(current->right);
                }
            }
            // increment the size of height after traverse
            height++;
        }
```
