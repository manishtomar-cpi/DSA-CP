#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int num) : val(num), left(nullptr), right(nullptr) {};
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
};

class BST
{
private:
    TreeNode *root;

public:
    BST() : root(nullptr) {};

    void insert(int num)
    {
        if (root == nullptr)
        {
            root = new TreeNode(num);
        }
        else
        {
            TreeNode *temp = root;
            TreeNode *parent = nullptr;

            while (temp)
            {
                parent = temp;
                if (temp->val < num)
                {
                    temp = temp->right;
                }
                else if (temp->val > num)
                {
                    temp = temp->left;
                }
                else
                {
                    cout << "already present!" << endl;
                    break;
                }
            }
            TreeNode *temp1 = new TreeNode(num);

            if (num > parent->val)
            {
                parent->right = temp1;
            }
            if (num < parent->val)
            {
                parent->left = temp1;
            }
        }
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
    /**
     * This function finds the minimum absolute difference between values
     * of any two different nodes in a Binary Search Tree (BST).
     *
     *  Approach:
     * - We perform an in-order traversal using a stack to visit nodes in sorted order.
     * - We maintain a vector `val_of_nodes` to store values of all previously visited nodes.
     * - For each current node, we compare its value with all values in `val_of_nodes`
     *   (until we reach its own value, which was just added), and calculate the absolute differences.
     * - We keep track of the smallest difference found during these comparisons.
     *
     *  This solution is not optimal because:
     *! - For each node, we compare with multiple previous nodes → leads to O(N²) time.
     * - We use extra space to store all node values → O(N) space.
     *
     *  This version works correctly but is inefficient for large trees.
     */

    int getMinimumDifference()
    { //! TIME: O(N^2), SPACE:O(N)
        stack<TreeNode *> childs;
        vector<int> val_of_nodes;
        TreeNode *current = root;
        int min_diff = INT32_MAX;

        while (current || !childs.empty())
        {
            while (current)
            {
                childs.push(current);
                val_of_nodes.push_back(current->val);
                current = current->left;
            }
            current = childs.top();
            childs.pop();
            int i = 0;
            // we maintain the vector of all nodes values so calculate with all and get min
            while (current->val != val_of_nodes[i])
            {
                int current_diff = abs(current->val - val_of_nodes[i]);
                min_diff = min(min_diff, current_diff);
                i++;
            }
            current = current->right;
        }
        return min_diff;
    }

    /**
     * This function finds the minimum absolute difference between values
     * of any two different nodes in a Binary Search Tree (BST) efficiently.
     *
     *  Approach:
     * - We perform an in-order traversal using a stack to visit nodes in sorted order.
     * - Since in-order traversal of a BST gives values in ascending order,
     *   the minimum absolute difference will always be between two **consecutive** values.
     * - We use a pointer `prev` to keep track of the previously visited node.
     * - At each node, we compute the absolute difference between `current->val` and `prev->val`,
     *   and update `minDiff` if it's smaller.
     *
     *  Optimized Version:
     * - Time Complexity: O(N) — each node is visited once.
     * - Space Complexity: O(1) extra — no need to store all previous node values.
     * - Faster and more memory-efficient for large trees.
     */
    int optimized()
    { // TIME:O(N), SPACE:O(1)
        TreeNode *current = root;
        TreeNode *prev = nullptr;
        int minDiff = INT32_MAX;
        stack<TreeNode *> childs;

        while (current || !childs.empty())
        {
            while (current)
            {
                childs.push(current);
                current = current->left;
            }
            if (prev)
            {
                minDiff = min(minDiff, abs(current->val - prev->val));
            }
            prev = current;
            current = current->right;
        }
        return minDiff;
    }

    /**
     *  Key Differences:
     *
     * 1. Comparison Logic:
     *    -  getMinimumDifference(): Compares each node with all previously visited nodes → O(N²)
     *    -  optimized(): Compares only with the immediately previous node in sorted order → O(N)
     *
     * 2. Space Usage:
     *    -  getMinimumDifference(): Stores all visited node values in a vector → O(N) space
     *    -  optimized(): Keeps only one pointer (`prev`) for last visited node → O(1) extra space
     *
     * 3. Efficiency:
     *    - optimized() is faster and more memory-efficient — better for large trees (up to 10⁴ nodes)
     */
};

int main()
{
    BST b1;
    b1.insert(1000);
    b1.insert(0);
    // b1.insert(6);
    // b1.insert(1);
    // b1.insert(3);

    b1.printTreeLevel();
    cout << b1.getMinimumDifference() << endl;

    return 0;
}