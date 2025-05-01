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

    vector<double> averageOfLevels()
    {
        vector<double> avg;
        double currentSum = 0;
        int count = 0;
        if (root == nullptr)
        {
            return avg;
        }
        queue<TreeNode *> level;
        level.push(root);
        level.push(nullptr); // to recognize the level means if we got null meands level end now do calculation
        while (!level.empty())
        {
            TreeNode *current = level.front();
            level.pop();
            // when level finish - do calculations
            if (current == nullptr)
            {
                avg.push_back(currentSum / count);
                currentSum = 0;
                count = 0;
                if (!level.empty())
                {
                    level.push(nullptr);
                }
            }
            else
            {
                // push the levels inside queue
                if (current->left)
                {
                    level.push(current->left);
                }
                if (current->right)
                {
                    level.push(current->right);
                }
                // and add the sum of level with number of odes in each level
                currentSum += current->val;
                count++;
            }
        }
        return avg;
    }
};

int main()
{
    BinaryTree b1;
    b1.insert();
    b1.averageOfLevels();

    return 0;
}