#include <iostream>
#include <queue>
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
    /*
        Problem: Check if a Binary Tree is Symmetric (Mirror of Itself)

        Definition:
        A tree is symmetric if the left subtree is a mirror reflection of the right subtree.

        ?Example (Symmetric):
             1
            / \
            2   2
            / \ / \
            3  4 4  3

        - 2 vs 2 ->
        - 3 vs 3 and 4 vs 4 -> Mirror match

        !Example (Not symmetric):
             1
            / \
            2   2
            \    \
            3    3

        - Missing mirror left child on right subtree
        - Not symmetric

        Approach (Iterative - BFS using queue):
        1. Handle base cases:
            - If tree is empty → not symmetric → return false.
            - If both left and right of root are null → symmetric → return true.
            - If one side is null and other isn’t → not symmetric → return false.
            - If left and right values don’t match → not symmetric.

        2. Use a queue to compare nodes in mirror positions:
            - Push root->left and root->right initially.
            - At every step, pop 2 nodes → current1 and current2.
            - Compare:
                current1->left with current2->right
                current1->right with current2->left
            - For each comparison:
                - If one is null and other isn't → return false.
                - If both are not null and their values don’t match → return false.
                - If valid → push both into queue for next level.

        3. If all mirror comparisons pass → return true.

        Key Observation:
        The tree is symmetric if and only if the left subtree is a mirror of the right subtree at every level.

        Time Complexity: O(n) — where n is the number of nodes (each node visited once)
        Space Complexity: O(n) — due to queue storing nodes in pairs
    */

    bool isSymmetric()
    {

        // edge cases
        if (root == nullptr)
        {
            return false;
        }
        if (!root->left && !root->right)
        {
            return true;
        }
        if ((root->right && !root->left) || (root->left && !root->right))
        {
            return false;
        }
        if (root->left->val != root->right->val)
        {
            return false;
        }

        queue<TreeNode *> nodes;
        nodes.push(root->left);
        nodes.push(root->right);
        while (!nodes.empty())
        {
            TreeNode *current1 = nodes.front();
            nodes.pop();
            TreeNode *current2 = nodes.front();
            nodes.pop();
            if (current1->left)
            {
                if (!current2->right)
                {
                    return false;
                }
                if (current1->left->val != current2->right->val)
                {
                    return false;
                }
                nodes.push(current1->left);
            }
            // why current2 -> right? because current1 -> left should be mirror of current2->right so for process these together save in queue one after another
            if (current2->right)
            {
                if (!current1->left)
                {
                    return false;
                }
                if (current1->left->val != current2->right->val)
                {
                    return false;
                }
                nodes.push(current2->right);
            }

            // then compare current1->right and current2->left
            if (current1->right)
            {
                if (!current2->left)
                {
                    return false;
                }
                if (current1->right->val != current2->left->val)
                {
                    return false;
                }
                nodes.push(current1->right);
            }
            if (current2->left)
            {
                if (!current1->right)
                {
                    return false;
                }
                if (current2->left->val != current1->right->val)
                {
                    return false;
                }
                nodes.push(current2->left);
            }
        }
        return true;
    }
};

int main()
{
    BinaryTree b1;
    b1.insert();
    cout << boolalpha;
    cout << b1.isSymmetric() << endl;
    return 0;
}