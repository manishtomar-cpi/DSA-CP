#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};

class BinaryTree
{
private:
    TreeNode *root;

public:
    BinaryTree() : root(nullptr) {};

    void insert()
    {
        queue<TreeNode *> nodes;
        if (root == nullptr)
        {
            cout << "Enter root data: ";
            int val;
            cin >> val;
            root = new TreeNode(val);
            nodes.push(root);
        }

        TreeNode *left;
        TreeNode *right;
        while (!nodes.empty())
        {
            TreeNode *current = nodes.front();
            nodes.pop();
            cout << "Enter left child of " << current->val << " : ";
            int leftChild;
            cin >> leftChild;
            if (leftChild == -1)
            {
                current->left = nullptr;
            }
            else
            {
                left = new TreeNode(leftChild);
                current->left = left;
                nodes.push(left);
            }
            cout << "Enter right child of " << current->val << " : ";
            int rightChild;
            cin >> rightChild;
            if (rightChild == -1)
            {
                current->right = nullptr;
            }
            else
            {

                right = new TreeNode(rightChild);
                current->right = right;
                nodes.push(right);
            }
        }
    }
    void printTree()
    {
        queue<TreeNode *> childs;
        if (root == nullptr)
        {
            cout << "empty!" << endl;
            return;
        }
        else
        {
            childs.push(root);
            while (!childs.empty())
            {
                TreeNode *current = childs.front();
                childs.pop();
                cout << current->val << " :";
                if (current->left)
                {
                    cout << " L: " << current->left->val;
                    childs.push(current->left);
                }
                if (current->right)
                {
                    cout << " R: " << current->right->val;
                    childs.push(current->right);
                }
                cout << endl;
            }
        }
    }
    /**
     * Approach: Iterative Flattening Using Stack for Right Nodes
     *
     * Goal: Flatten the binary tree into a right-skewed linked list following preorder traversal.
     *
     * Steps:
     * 1. If the root is NULL, simply return.
     *
     * 2. Initialize a stack to temporarily store right nodes (`rightNodes`).
     *    Also, initialize `current` pointer to start from the root.
     *
     * 3. Start a loop while `current` is not NULL:
     *
     *    a. If `current` has a left child:
     *       - If `current` also has a right child, push the right child into the stack (save it for later).
     *       - Move the left child to the right of current (`current->right = current->left`).
     *       - Set `current->left` to NULL (because we only want right children now).
     *       - Move `current` to its new right (which was originally left).
     *
     *    b. If `current` doesn't have a left child:
     *       - If `current` has a right child, continue moving right (no special action).
     *       - If `current` has no right child but the stack is not empty:
     *         - Pop a node from the stack.
     *         - Connect it as `current->right`.
     *         - Move `current` to this new right.
     *
     *    c. If `current` is a leaf node (no left, no right) and stack is empty:
     *       - Break the loop (flattening is done).
     *
     * 4. Done. The tree is now flattened into a linked list in preorder!
     *
     * Notes:
     * - Space complexity is O(N) in the worst case because we are using a stack.
     * - Time complexity is O(N) because each node is visited once.
     *
     * Example Flow:
     *
     *      1
     *     / \
     *    2   5
     *   / \    \
     *  3   4    6
     *
     * After flatten:
     *
     * 1 -> 2 -> 3 -> 4 -> 5 -> 6
     * (all left pointers are NULL)
     *
     */

    void flatten()
    {
        if (root == nullptr)
        {
            return;
        }
        stack<TreeNode *> rightNodes;
        TreeNode *current = root;
        while (current)
        {
            while (current->left)
            {
                // if current right save it in stack
                if (current->right)
                {
                    rightNodes.push(current->right);
                }
                // now link current->left to right side
                current->right = current->left;
                current->left = nullptr;
                current = current->right;
            }

            // if we are not reaching leaf
            if (current->right)
            {
                rightNodes.push(current->right);
            }

            // if we are reached leaf means according to the pre order the right is now nest so we go to stack top and link the top one in right of current
            if (!current->left)
            {
                if (!rightNodes.empty())
                {
                    current->right = rightNodes.top();
                    current = current->right;
                    rightNodes.pop();
                }
            }

            // if all nodes are traversed
            if ((!current->left && !current->right) && (rightNodes.empty()))
            {
                break;
            }
        }
    }

    TreeNode *getRoot()
    {
        return root;
    }

    void printList()
    {
        if (root == nullptr)
        {
            return;
        }
        if (!root->right)
        {
            return;
        }
        TreeNode *temp = root;
        while (temp)
        {
            cout << temp->val << " ";
            if (temp->left)
            {
                cout << " have left too! ";
            }
            temp = temp->right;
        }
        cout << endl;
    }
};

int main()
{
    BinaryTree b1;
    b1.insert();
    b1.printTree();
    b1.flatten();
    b1.printList();
    return 0;
}