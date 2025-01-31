#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;

    TreeNode() : left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

class BST
{
private:
    TreeNode *root = nullptr;

public:
    BST() : root(nullptr) {};

    void insert(int data)
    {
        if (root == nullptr)
        {
            root = new TreeNode(data);
            cout << data << " added on root!" << endl;
            return;
        }
        else
        {
            TreeNode *current = root;   // for traversing the tree to add new node
            TreeNode *parent = nullptr; // works as the prev to add the new data

            while (current)
            {                     // means we will go in depth as we can to add new node
                parent = current; // because we are going to modify the current below
                if (current->val < data)
                {
                    current = current->right; // the new value should be in the right
                }
                else if (current->val > data)
                {
                    current = current->left; // should be in left;
                }
                else
                {
                    cout << "cannot add " << data << " its already in the tree!" << endl;
                    return;
                }
            }
            // now we have parent node where we will insert the new node
            if (parent->val < data)
            {
                // the new node should be in right
                TreeNode *temp = new TreeNode(data);
                parent->right = temp;
                cout << "inserted " << data << " in right of " << parent->val << " !" << endl;
            }
            else
            {
                parent->left = new TreeNode(data); // we can do both type of insertion
                cout << "inserted " << data << " in left of " << parent->val << " !" << endl;
            }
        }
    }
    /*
    *Step 1: Find the Node to Delete
    Start from the root and search for the node to be deleted (data).

    Use BST properties:
    If data < current->val, move left.
    If data > current->val, move right.
    Keep track of the parent node.
    If the node is not found (current == nullptr), print "data not present in tree" and exit.

    *Step 2: Handle Different Cases of Deletion

    ?Case 1: Node is a Leaf (No Children)
    If current has no left and right child:
    If current == root, set root = nullptr.
    If current is the left child of its parent, set parent->left = nullptr.
    If current is the right child of its parent, set parent->right = nullptr.
    Delete the node (delete current).

    ?Case 2: Node Has Only a Left Child
    If current has no right child but has a left child:
    If current == root, set root = current->left.
    If current is left child of parent, update parent->left = current->left.
    If current is right child of parent, update parent->right = current->left.
    Delete the node (delete current).

    ?Case 3: Node Has Only a Right Child
    If current has no left child but has a right child:
    If current == root, set root = current->right.
    If current is left child of parent, update parent->left = current->right.
    If current is right child of parent, update parent->right = current->right.
    Delete the node (delete current).

    ?Case 4: Node Has Two Children
    Find the In-Order Successor (smallest node in right subtree):
    Set successor = current->right.
    While successor->left exists, move left to find the smallest node.
    Keep track of successorParent.
    Replace the Value:
    Set current->val = successor->val.
    Delete the Successor:
    If successor is the direct right child of current, update current->right = successor->right.
    Otherwise, update successorParent->left = successor->right.
    Delete the successor node (delete successor).
    */
    void deleteVal(int data)
    {
        // find the node to delete
        TreeNode *current = root;
        TreeNode *parent = nullptr;
        while (current && current->val != data)
        {
            parent = current;
            if (data < current->val)
            {
                // find in left
                current = current->left;
            }
            else
            {
                // go right
                current = current->right;
            }
        }
        if (current == nullptr)
        {
            // means value not found
            cout << data << " not present in tree" << endl;
            return;
        }
        // case 1: the leaf node
        if (!current->left && !current->right)
        {
            // if only root in the tree
            if (current == root)
            {
                root = nullptr;
            }

            // if the current is left leaf
            else if (parent->left == current)
            {
                parent->left = nullptr;
            }
            // if right leaf
            else
            {
                parent->right = nullptr;
            }
            cout << "Deleted leaf node: " << current->val << endl;
            delete current;
        }
        // case 2: if the deleted node have left subtree
        else if (!current->right)
        {
            // if root
            if (current == root)
            {
                root = current->left;
            }
            // now checking where to place the new node in parent
            else if (parent->left == current)
            {
                parent->left = current->left;
            }
            else
            {
                parent->right = current->left;
            }
            cout << "Deleted node " << current->val << " with only left child" << endl;
            delete current;
        }
        // case 3: if deleted node have right child
        else if (!current->left)
        {
            if (current == root)
            {
                root = current->right;
            }
            else if (parent->left == current)
            {
                parent->left = current->right;
            }
            else
            {
                parent->right = current->right;
            }
            cout << "Deleted node " << current->val << " with only right child" << endl;
            delete current;
        }
        // case 4: have both right and left child
        else
        {
            // so are going right Using the In-Order Successor (Leftmost node in right subtree)
            TreeNode *sucessor = current->right;
            TreeNode *sucessorParent = current;
            while (sucessor->left)
            {
                sucessorParent = sucessor;
                sucessor = sucessor->left;
            }
            current->val = sucessor->val;
            // If successor is the direct right child of the node being deleted, means  no left node of the sucessor
            if (sucessorParent == current)
            {
                sucessorParent->right = sucessor->right;
            }
            else
            {
                // if the successor have the right child then if should be the left of parent
                sucessorParent->left = sucessor->right;
            }
            cout << "deleted " << data << " with both children replaced with " << sucessor->val << endl;
            delete sucessor;
        }
    }

    void printTree()
    {
        // inorder traversal
        stack<TreeNode *> childs;
        if (!root)
            return;
        TreeNode *current = root;

        while (!childs.empty() || current)
        {

            while (current)
            {
                childs.push(current);

                current = current->left;
            }
            current = childs.top();
            childs.pop();
            cout << current->val << " ";
            current = current->right;
        }
    }

    bool hasValue(int val)
    {
        TreeNode *current = root;
        while (current)
        {
            if (current->val == val)
            {
                return true;
            }
            else if (current->val > val)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return false;
    }

    void printTreeLevel()
    {
        if (!root)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        queue<TreeNode *> childs;
        childs.push(root);
        childs.push(nullptr); // Marker for end of level

        while (!childs.empty())
        {
            TreeNode *current = childs.front();
            childs.pop();

            if (current == nullptr)
            {
                cout << endl; // End of level

                if (!childs.empty())
                {
                    childs.push(nullptr); // Add marker for the next level
                }
                continue; // Skip the remaining code for `nullptr`
            }

            cout << current->val << " ";

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
};

int main()
{
    BST b1;
    b1.insert(10);
    b1.insert(14);
    b1.insert(9);
    b1.insert(8);
    b1.printTree();
    cout << boolalpha;
    cout << b1.hasValue(15) << endl;

    return 0;
}