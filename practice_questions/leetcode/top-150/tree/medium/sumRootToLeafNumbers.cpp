#include <iostream>
#include <queue>
#include <stack>
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
     * Approach:
     * - We are doing an iterative depth-first traversal (similar to in-order traversal).
     * - We maintain two variables:
     *     - currentSum: to build the number along the root-to-current path.
     *     - totalSum: to store the final sum of all root-to-leaf numbers.
     * - As we go down the tree (left side), we multiply currentSum by 10 and add the current node's value.
     * - We push each visited node into the stack to remember our path.
     * - When we reach a leaf node (no left and right child), we add currentSum to totalSum.
     * - After visiting a node and its left subtree:
     *     - If it has a right child not yet visited, we move to the right child.
     *     - Else, we backtrack (pop from the stack) and remove the last digit from currentSum (by dividing by 10).
     * - We use a lastVisited pointer to keep track of whether we have already visited the right child,
     *   so we know when to backtrack.
     * - This method ensures that currentSum correctly represents the number formed along the path at any moment.
     */
    int sumNumbers()
    {
        int currentSum = 0;
        int totalSum = 0;
        stack<TreeNode *> st;
        unordered_map<TreeNode *, bool> hash;
        TreeNode *current = root;
        TreeNode *lastVisited = nullptr;
        while (current || !st.empty())
        {
            // go deep left as we can
            while (current)
            {
                currentSum = (currentSum * 10) + current->val;
                st.push(current);
                current = current->left;
            }
            // current is now on top
            current = st.top();

            // if that node is leaf node means time to calculate total sum
            if (!current->left && !current->right)
            {
                totalSum += currentSum;
            }

            // if right exist and not visited
            if (current->right && current->right != lastVisited)
            {
                current = current->right;
            }
            else
            // backtracking
            {
                lastVisited = current;
                st.pop();
                currentSum /= 10;
                current = nullptr;
            }
        }
        return totalSum;
    }
};

int main()
{
    BinaryTree b1;
    b1.insert();
    cout << b1.sumNumbers() << endl;
    return 0;
}