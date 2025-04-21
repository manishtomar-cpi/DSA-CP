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

    bool isSame(TreeNode *p, TreeNode *q)
    {
        //edge cases 
        if (!p && !q)
        {
            return true;
        }
        if (!p || !q)
        {
            return false;
        }
        if (p->val != q->val)
        {
            return false;
        }

        //2 queues for both trees 
        queue<TreeNode *> first;
        queue<TreeNode *> second;
        first.push(p);
        second.push(q);

        while (!first.empty() && !second.empty())
        {
            TreeNode *firstCurrent = first.front();
            TreeNode *secondCurrent = second.front();
            first.pop();
            second.pop();
            if ((firstCurrent->left && !secondCurrent->left) || (secondCurrent->left && !firstCurrent->left) || (firstCurrent->right && !secondCurrent->right) || (secondCurrent->right && !firstCurrent->right))
            {
                return false;
            }
            else
            {
                if (firstCurrent->left && secondCurrent->left)
                {
                    if ((firstCurrent->left->val != secondCurrent->left->val))
                    {
                        return false;
                    }
                    else
                    {
                        first.push(firstCurrent->left);
                        second.push(secondCurrent->left);
                    }
                }
                if (secondCurrent->right && firstCurrent->right)
                {
                    if ((firstCurrent->right->val != secondCurrent->right->val))
                    {
                        return false;
                    }
                    else
                    {
                        first.push(firstCurrent->right);
                        second.push(secondCurrent->right);
                    }
                }
            }
        }
        return true;
    }

    TreeNode *getRoot()
    {
        return root;
    }
};

int main()
{
    BinaryTree b1;
    BinaryTree b2;
    b1.insert();
    b2.insert();
    b1.printTree();
    b2.printTree();
    cout << boolalpha;
    cout << b1.isSame(b1.getRoot(), b2.getRoot()) << endl;
    ;
    return 0;
}