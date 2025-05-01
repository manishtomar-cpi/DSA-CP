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
     * Approach:
     * - Use a queue for level order traversal (BFS) and a stack to reverse the order when needed.
     * - Push root into the queue followed by a nullptr to mark the end of the first level.
     * - For even turns (left to right), add child node values directly to current level.
     * - For odd turns (right to left), push child nodes into a stack to reverse the order later.
     * - When nullptr is encountered, it means the level is complete:
     *      - Pop all nodes from the stack (if it was right-to-left) into the current level.
     *      - Push the current level into the result.
     *      - Add another nullptr if there are more nodes to process.
     * - Repeat the process while the queue is not empty.
     * - Return all collected levels in zigzag order.
     */

    vector<vector<int>> zigzagLevelOrder()
    {
        vector<vector<int>> allLevels;
        vector<int> currentLevel;
        int turn = 1;
        queue<TreeNode *> childs;
        stack<TreeNode *> st;
        if (root == nullptr)
        {
            return allLevels;
        }
        childs.push(root);
        childs.push(nullptr);
        allLevels.push_back({root->val});
        while (!childs.empty())
        {
            TreeNode *current = childs.front();
            childs.pop();
            if (current == nullptr)
            {
                if (turn % 2 != 0)
                {
                    while (!st.empty())
                    {
                        currentLevel.push_back(st.top()->val);
                        st.pop();
                    }
                    allLevels.push_back(currentLevel);
                }
                if (turn % 2 == 0)
                {
                    allLevels.push_back(currentLevel);
                }
                if (!childs.empty())
                {
                    childs.push(nullptr);
                }
                turn++;
                currentLevel.clear();
            }
            else
            {
                if (turn % 2 == 0)
                {
                    if (current->left)
                    {
                        childs.push(current->left);
                        currentLevel.push_back(current->left->val);
                    }
                    if (current->right)
                    {
                        childs.push(current->right);
                        currentLevel.push_back(current->right->val);
                    }
                }
                if (turn % 2 != 0)
                {
                    if (current->left)
                    {
                        childs.push(current->left);
                        st.push(current->left);
                    }
                    if (current->right)
                    {
                        childs.push(current->right);
                        st.push(current->right);
                    }
                }
            }
        }
        return allLevels;
    }

    /**
     * Approach:
     * - Use a queue to do normal level order traversal (BFS).
     * - For each level, create a vector of the correct size.
     * - If we are going left to right, fill the vector from start to end.
     * - If we are going right to left, fill the vector from end to start.
     * - After finishing one level, push the vector to the final result.
     * - Toggle the direction (left to right ↔ right to left) after each level.
     */
    vector<vector<int>> zigzagLevelOrderOptimise(TreeNode *root)
    {
        vector<vector<int>> allLevels;
        if (root == nullptr)
        {
            return allLevels;
        }
        queue<TreeNode *> nodes;
        nodes.push(root);
        bool rigtToLeft = false;
        while (!nodes.empty())
        {
            int size = nodes.size(); // means the current level size
            vector<int> currentLevel(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = nodes.front();
                nodes.pop();
                int index = !rigtToLeft ? i : size - 1 - i; // if left to right we will push normal , if not then we push from last , so vector will filled according to requriments.
                currentLevel[index] = temp->val;
                if (temp->left)
                    nodes.push(temp->left); // now time to push next level inside the queue
                if (temp->right)
                    nodes.push(temp->right);
            }
            // after traverse currnet level in above for loop push that in the allLevels
            allLevels.push_back(currentLevel);
            rigtToLeft = !rigtToLeft; // updtae left to right
        }
        return allLevels;
    }
};

int main()
{
    BinaryTree b1;
    b1.insert();
    b1.zigzagLevelOrder();
    return 0;
}