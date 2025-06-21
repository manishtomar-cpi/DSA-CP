#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
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
     *  Problem: Check if a binary tree has a root-to-leaf path that sums up to targetSum
     *
     *  Constraints:
     * - A path must go from root → leaf (no partial or mid paths)
     * - We must visit every node to make sure we don’t miss a valid path
     *
     *  Approach: Iterative DFS using a Stack
     *  Why Iterative? You wanted to avoid recursion and practice manual traversal
     *  Traversal type: Postorder (Left → Right → Node), because we need to know
     *  when both left and right children are processed before checking the node
     *
     *  Variables:
     * - stack<TreeNode*> childs → manually simulate DFS traversal
     * - TreeNode* current → the current node we're processing
     * - TreeNode* lastVisited → helps us know if we just came from a right child (for postorder logic)
     * - int sum → keeps track of current path sum from root to current node
     *
     *  Flow:
     * 1. Start from root and keep going left (just like DFS)
     * 2. While going down, add node values to `sum` and push node into stack
     * 3. When you can't go left anymore:
     *    - Peek the top of the stack (don’t pop yet!)
     *    - If the right child exists and hasn’t been visited yet → move to it
     *    - Else: this is either a leaf node or both children are processed
     *         → Check if it's a leaf and if the sum matches targetSum
     *         → Subtract current node from sum and pop (backtrack)
     *
     *  Edge Cases Covered:
     * - Null tree: return false
     * - Single-node tree: must check if root is a leaf and val == targetSum
     * - Negative numbers? Handled fine because we still add values normally
     *
     *  Result:
     * - Time Complexity: O(n)
     * - Space Complexity: O(h), where h is height of the tree
     */

    bool hasPathSum(int targetSum)
    {
        int currentSum = 0;
        bool flag = false;
        stack<TreeNode *> childs;
        if (root == nullptr)
        {
            return false;
        }
        if (!root->left && !root->right)
        {
            if (root->val == targetSum)
            {
                return true;
            }
        }
        TreeNode *current = root;
        TreeNode *lastVisited = nullptr;
        int sum = 0;
        while (current || !childs.empty())
        {
            // Step 1: Go as left as possible
            while (current)
            {
                childs.push(current);
                sum += current->val;
                current = current->left;
            }

            TreeNode *peek = childs.top();
            // Step 2: If right exists and not visited, go right
            if (peek->right && lastVisited != peek->right)
            {
                current = peek->right;
            }
            else
            {
                // Step 3: Check if it's a leaf and sum matches
                if (!peek->right && !peek->left && sum == targetSum)
                {
                    return true;
                }

                //Backtracking
                sum -= peek->val;
                lastVisited = peek;
                childs.pop();
            }
        }
        return false;
    }
};

int main()
{
    BinaryTree b1;
    b1.insert();
    cout << boolalpha;
    cout << b1.hasPathSum(-5) << endl;
    return 0;
}