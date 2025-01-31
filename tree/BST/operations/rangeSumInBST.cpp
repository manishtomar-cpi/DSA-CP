#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode() : left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

class BST
{
private:
    TreeNode *root;

public:
    BST() : root(nullptr) {};

    void insert(int data)
    {
        if (!root)
        {
            root = new TreeNode(data);
            cout << data << " added on root!" << endl;
            return;
        }
        else
        {
            TreeNode *current = root;
            TreeNode *parent = nullptr;
            while (current)
            {
                // searching place for new node
                if (data < current->val)
                {
                    // new node should be at left
                    parent = current;
                    current = current->left;
                }
                else if (data > current->val)
                {
                    // should be at right side
                    parent = current;
                    current = current->right;
                }
                else
                {
                    cout << data << " already in the tree: cannot add!" << endl;
                    return;
                }
            }
            // now we have the node where the new node will be inserted
            if (data < parent->val)
            {
                parent->left = new TreeNode(data);
                cout << data << " added in left of " << parent->val << " !" << endl;
                return;
            }
            else
            {
                parent->right = new TreeNode(data);
                cout << data << " added in right of " << parent->val << " !" << endl;
                return;
            }
        }
    }

    void printLevelWise()
    {
        queue<TreeNode *> childs;
        if (!root)
        {
            return;
        }
        childs.push(root);
        childs.push(nullptr);
        while (!childs.empty())
        {
            TreeNode *current = childs.front();
            childs.pop();
            if (current == nullptr)
            {
                cout << endl;
                if (!childs.empty())
                {
                    childs.push(nullptr);
                    continue;
                }
            }
            else
            {
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
    }

    int rangeSum(int low, int high)
    {
        if (!root)
            return INT16_MIN;
        queue<TreeNode *> childs;
        childs.push(root);
        int sum = 0;
        while (!childs.empty())
        {
            TreeNode *current = childs.front();
            childs.pop();
            if (current->val >= low && current->val <= high)
            {
                sum += current->val;
            }
            //the current is equal or less so it might be chance both childs will in the range
            if (current->val <= high)
            {
                if (current->right)
                {
                    childs.push(current->right);
                }
                if (current->left)
                {
                    childs.push(current->left);
                }
            }
            //in this case might be left child in the range
            if (current->val > high && current->left)
            {
                childs.push(current->left);
            }
        }
        return sum;
    }
};

int main()
{
    BST b1;
    b1.insert(5);
    b1.insert(3);
    b1.insert(10);
    b1.insert(1);
    b1.insert(4);
    b1.insert(6);
    b1.insert(15);
    b1.insert(2);
    b1.printLevelWise();
    cout << boolalpha;
    cout << b1.rangeSum(1, 5) << endl;
    return 0;
}