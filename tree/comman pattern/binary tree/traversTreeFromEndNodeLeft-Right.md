```cpp
stack<BTNode *> childs;
BTNode *current = root;
BTNode \*lastVisited = nullptr; // this helps us to traverse the right subtree only once

        while (current || !childs.empty())
        {
            while (current)
            {
                // traverse the left subtree
                childs.push(current);
                vec.push_back(current->data);
                current = current->left;
            }
            //top is now current
            current = childs.top();

            //if the current have right tree
            if (current->right && current->right != lastVisited)
            {
                // traverse the right subtree
                current = current->right;
            }
            else
            {
                // backtracking
                childs.pop();
                vec.pop_back();
                lastVisited = current;
                current = nullptr;
            }
        }
```
