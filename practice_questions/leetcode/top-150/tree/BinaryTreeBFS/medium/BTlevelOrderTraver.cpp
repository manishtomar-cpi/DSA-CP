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

    vector<vector<int>> levelOrder()
    {
        vector<vector<int>> vec;
        vector<int> currentLevel;
        if (root == nullptr)
        {
            return vec;
        }
        queue<TreeNode *> level;
        level.push(root);
        level.push(nullptr);

        while (!level.empty())
        {
            TreeNode *current = level.front();
            level.pop();
            if (current == nullptr)
            {
                vec.push_back(currentLevel);
                currentLevel.clear();
                if (!level.empty())
                {
                    level.push(nullptr);
                }
            }
            else
            {
                if (current->left)
                {
                    level.push(current->left);
                }
                if (current->right)
                {
                    level.push(current->right);
                }
                currentLevel.push_back(current->val);
            }
        }

        return vec;
    }
};

int main()
{
    BinaryTree b1;
    b1.insert();
    b1.levelOrder();

    return 0;
}