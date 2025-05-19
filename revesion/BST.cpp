#include <iostream>
#include <queue>
using namespace std;

class BSTNode
{
public:
    int val;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int num) : val(num), left(nullptr), right(nullptr) {};
    BSTNode() : val(0), left(nullptr), right(nullptr) {};
};

class BST
{
private:
    BSTNode *root;

public:
    BST() : root(nullptr) {};

    void insert(int num)
    {
        if (root == nullptr)
        {
            root = new BSTNode(num);
        }
        else
        {
            BSTNode *temp = root;
            BSTNode *parent = nullptr;

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
            BSTNode *temp1 = new BSTNode(num);

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

        queue<BSTNode *> childs;
        childs.push(root);
        childs.push(nullptr); // Marker for end of level

        while (!childs.empty())
        {
            BSTNode *current = childs.front();
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
    BST b1;
    b1.insert(9);
    b1.insert(5);
    b1.insert(18);
    b1.insert(2);
    b1.insert(15);

    b1.printTreeLevel();

    return 0;
}