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

    int maxDepth()
    {
        int level = 0;
        queue<TreeNode *> childs;
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            childs.push(root);
            childs.push(nullptr);
            while (!childs.empty())
            {
                TreeNode *current = childs.front();
                childs.pop();
                if (current == nullptr)
                {
                    level++;
                    if (!childs.empty())
                    {
                        childs.push(nullptr);
                        continue;
                    }
                }
                else
                {
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
        }
        return level;
    }
};

int main()
{
    BinaryTree b1;
    b1.insert();
    b1.printTree();
    cout << b1.maxDepth() << endl;
    return 0;
}