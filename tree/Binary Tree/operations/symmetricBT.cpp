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
    Check Base Case:

    If the tree is empty (root == nullptr), it is symmetric. Return true.
    Use a Queue:

    Create a queue to hold pairs of nodes to compare.
    Enqueue Root’s Children:

    Add the left and right children of the root as a pair to the queue.
    Iteratively Compare Nodes:

    While the queue is not empty:
    Dequeue a pair of nodes.
    If both nodes are nullptr, continue to the next pair (they are symmetric at this level).
    If one node is nullptr or their values are not equal, return false (not symmetric).
    Enqueue their children as pairs in the following order:
    Left child of the first node and right child of the second node.
    Right child of the first node and left child of the second node.
    Return True:

    If all pairs are symmetric and the queue is empty, the tree is symmetric. Return true.
    */
    bool isSymmetric()
    {
        queue<BTNode *> childs;
        if (!root) // Base Case
            return false;
        childs.push(root->left);
        childs.push(root->right);

        while (!childs.empty())
        {
            BTNode *leftNode = childs.front();
            childs.pop();
            BTNode *rightNode = childs.front();
            childs.pop();

            if (!leftNode && !rightNode)
                continue; // means we are on the leaf

            if ((!leftNode || !rightNode) || (leftNode->data != rightNode->data))
                return false; // means not symmetric

            childs.push(leftNode->left);   // first left of the left
            childs.push(rightNode->right); // then right of the right because they should sym if the tree is sym
            childs.push(leftNode->right);  // same for others teo
            childs.push(rightNode->left);
        }

        return true;
    }
};

int main()
{
    BTNode bt1;
    bt1.create();
    bt1.print();
    cout << boolalpha;
    cout << bt1.isSymmetric() << endl;
    return 0;
}