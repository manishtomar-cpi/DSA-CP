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
    D,L,R is the order(Data, Left, Right)
    STEP-1: push the root into stack
    STEP-2: make current to top, and pop the front, then print the data of the current
    STEP-3: check for right subtree first if yes, push it into stack, then check of right sub tree push it into stack
    STEP5-4: repeat step 2 and step 3 until stack became empty
    */

    void getPreorder()
    {
        stack<BTNode *> childs;
        // step1
        childs.push(root);
        while (!childs.empty()) // step 4
        {
            // step2
            BTNode *current = childs.top();
            childs.pop();
            cout << current->data << ", ";
            // step 3
            if (current->right)
            {
                childs.push(current->right);
            }
            if (current->left)
            {
                childs.push(current->left);
            }
        }
    }
};

int main()
{
    BTNode bt1;
    bt1.create();
    bt1.print();
    bt1.getPreorder();
    return 0;
}