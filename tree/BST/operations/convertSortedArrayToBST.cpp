#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class TreeNode
{
private:
    TreeNode *left;
    TreeNode *right;
    int val;
    /*
    Base Case:
    If the subarray is empty (start > end), return nullptr.

    Recursive Step:
    Find the middle of the current subarray.
    Create a new tree node with the middle value.
    Recursively call the function to create the left and right subtrees for the left and right halves of the array.

    */
    // helper fundtion for recusrion
    TreeNode *helper(vector<int> &vec, int start, int end)
    { // giving vector and start end for right and left subtree

        if (start > end)
        { // base case ->
            /*
                Let’s take a sorted array:
                nums = [-10, -3, 0, 5, 9]

                First Call (Entire Array):
                start = 0, end = 4
                mid = (0 + 4) / 2 = 2
                Create root: TreeNode(0)
                Now:
                Left subtree: start = 0, end = 1 (nums[0] to nums[1])
                Right subtree: start = 3, end = 4 (nums[3] to nums[4])

                Second Call (Left Subtree):
                start = 0, end = 1
                mid = (0 + 1) / 2 = 0
                Create left child: TreeNode(-10)
                Now:
                Left subtree: start = 0, end = -1 → Base case (start > end), return nullptr.
                Right subtree: start = 1, end = 1

                Third Call (Right Subtree of -10):
                start = 1, end = 1
                mid = (1 + 1) / 2 = 1
                Create right child: TreeNode(-3)
                Now:
                Left subtree: start = 1, end = 0 → Base case (start > end), return nullptr.
                Right subtree: start = 2, end = 1 → Base case (start > end), return nullptr.
            */
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(vec[mid]);
        root->left = helper(vec, start, mid - 1); // for left subtree from start to mid-1
        root->right = helper(vec, mid + 1, end);  // for right subtree it should be from mid+1

        return root;
    }

public:
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode() : left(nullptr), right(nullptr) {};

    TreeNode *arrayToBST(vector<int> &vec)
    {
        int n = vec.size();

        return helper(vec, 0, n - 1);
    }

    void inOrderTraversal(TreeNode *root)
    {
        if (!root)
            return;
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
    void printTreeLevel(TreeNode *root)
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
    vector<int> vec = {2, 4, 6, 8, 10, 12, 14, 16, 18, 19, 20};
    TreeNode *root = nullptr;
    TreeNode t1;
    root = t1.arrayToBST(vec);
    t1.inOrderTraversal(root);

    return 0;
}