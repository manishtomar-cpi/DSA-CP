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
     * This function finds the kth smallest element in a Binary Search Tree (BST).
     * 
     *  Approach:
     * - In a BST, in-order traversal (left → root → right) gives node values in sorted order.
     * - So, the kth smallest element is simply the kth value visited during in-order traversal.
     * - We use an iterative in-order traversal with a stack to avoid recursion.
     * 
     *  How it works:
     * - Traverse to the leftmost node, pushing nodes onto the stack.
     * - Start visiting (popping) nodes from the stack and count each visit.
     * - When count == k, return the current node’s value.
     * 
     *  Efficient because:
     * - Stops traversal as soon as kth node is found (does not process the entire tree).
     * 
     * ⏱️ Time Complexity:
     * - Worst case: O(N) (if the kth smallest is the largest element)
     * - Best case: O(k) (early stop)
     * 
     *  Space Complexity:
     * - O(H), where H is the height of the tree (for the stack)
     * - O(log N) for balanced BST, O(N) for skewed BST
     */

    int kthSmallest(int k)
    {
        TreeNode *current = root;
        int count = 0;
        stack<TreeNode *> st;
        while (current || !st.empty())
        {
            while (current)
            {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            count++;
            if (count == k)
            {
                return current->val;
            }
            current = current->right;
        }
        return -1;
    }
};

int main()
{
    BST b1;
    b1.insert(5);
    b1.insert(3);
    b1.insert(6);
    b1.insert(2);
    b1.insert(4);
    b1.insert(1);

    b1.printTreeLevel();
    cout << b1.kthSmallest(3) << endl;
    return 0;
}