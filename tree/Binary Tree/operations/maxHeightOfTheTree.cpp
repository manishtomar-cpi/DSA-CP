#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class BTNode
{
private:
    BTNode *root;
    BTNode *left;
    BTNode *right;
    int data;

    void inOrder(BTNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << ", ";
        inOrder(root->right);
    }

public:
    BTNode(int val) : data(val), root(nullptr), left(nullptr), right(nullptr) {};
    BTNode() : root(nullptr), left(nullptr), right(nullptr) {};

    void create()
    {
        cout << "Enter root data: ";
        int rootData;
        cin >> rootData;
        cout << endl;
        root = new BTNode(rootData);
        queue<BTNode *> childs;
        childs.push(root);

        while (!childs.empty())
        {
            BTNode *current = childs.front();
            childs.pop();
            cout << "Enter left child of " << current->data << ": ";
            int left;
            cin >> left;
            cout << endl;
            if (left != -1) //-1 means no child
            {
                // create
                BTNode *leftNode = new BTNode(left);
                // making connection
                current->left = leftNode;
                // push into queue
                childs.push(leftNode);
            }
            if (left == -1)
            {
                cout << "No left child of: " << current->data << endl;
            }
            cout << "Enter right child of " << current->data << ": ";
            int right;
            cin >> right;
            cout << endl;
            if (right != -1)
            {
                // create
                BTNode *rightNode = new BTNode(right);
                // making connection
                current->right = rightNode;
                // push into queue
                childs.push(rightNode);
            }
            if (right == -1)
            {
                cout << "No right child of " << current->data << endl;
            }
        }
    }

    void print()
    {
        queue<BTNode *> childs;
        if (root == nullptr)
        {
            return;
        }
        childs.push(root);

        while (!childs.empty())
        {
            BTNode *current = childs.front();
            childs.pop();
            cout << current->data << ": ";
            if (current->left)
            {
                childs.push(current->left);
                cout << "L" << current->left->data << ", ";
            }
            if (current->right)
            {
                childs.push(current->right);
                cout << "R" << current->right->data << ", ";
            }
            cout << endl;
        }
    }
    /*
    -If the root is nullptr, the height is 0.
    -Initialize a queue and push the root node into it.
    -While the queue is not empty:
        --Determine the number of nodes in the current level (levelSize).
        --For each node at the current level:
        --Pop the node from the queue.
        --Push its left child into the queue if it exists.
        --Push its right child into the queue if it exists.
    -Increment the height after processing all nodes at the current level.
    -Return the height.
    */

    int getMaxHeight()
    {
        queue<BTNode *> childs;
        childs.push(root);
        int height = 0;

        if (root == nullptr)
        {
            return 0;
        }
        while (!childs.empty())
        {
            int levelSize = childs.size(); // current size of level
            for (int i = 0; i < levelSize; i++)
            {
                BTNode *current = childs.front();
                childs.pop();
                // traverse all the nodes of current level
                if (current->left)
                {
                    childs.push(current->left);
                }
                if (current->right)
                {
                    childs.push(current->right);
                }
            }
            // increment the size of height after traverse
            height++;
        }

        return height;
    }
};

int main()
{
    BTNode bt1;
    bt1.create();
    bt1.print();
    cout << "height of the tree is: " << bt1.getMaxHeight() << endl;

    return 0;
}