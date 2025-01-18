Traversing the tree level wise means all nodes of the that level then come to the next level

````cpp
         // the logic is first we will travers each level then increase height
            while (!childs.empty())
            {
                int levelSize = childs.size(); // taking level size

                // iterate all the roots of that level
                for (int i = 0; i < levelSize; i++)
                {
                    TreeNode *current = childs.front();
                    childs.pop();
                    // iterate over all the childs of that root
                    for (int j = 0; j < current->childrens.size(); j++)
                    {
                        childs.push(current->childrens[j]);
                    }
                }
                // after treversing the complete level increase height
                height++;
            }
            ```
````
