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

    /*
    1. Initialization:
    Start from the last element in the postorder array as the root.
    Use a stack to keep track of nodes whose children are being processed.
    Use an inorderIndex pointer starting from the end of the inorder array.

    2. Traverse Postorder (Reversed):
    For each node in the postorder array (traversing from right to left):
    If the stack's top does not match inorder[inorderIndex], the current node is part of the right subtree:
    Attach it as the right child of the last node in the stack.
    Push it onto the stack.
    Otherwise, the left subtree needs to be processed:
    Pop nodes from the stack until the stack's top no longer matches inorder[inorderIndex].
    Attach the current node as the left child of the last popped node.
    Push it onto the stack.
    */

    BTNode *makeTree(vector<int> postOrder, vector<int> inOrder)
    {
        stack<BTNode *> childs;
        root = new BTNode(postOrder[postOrder.size() - 1]);
        childs.push(root);
        int inOrderIndex = inOrder.size() - 1; // start from last

        for (int i = postOrder.size() - 2; i >= 0; i--)
        {
            BTNode *current = childs.top();
            // adding left
            if (current->data != inOrder[inOrderIndex])
            {
                BTNode *rightChild = new BTNode(postOrder[i]);
                current->right = rightChild;
                childs.push(current->right);
            }
            else
            {
                // adding right
                while (!childs.empty() && childs.top()->data == inOrder[inOrderIndex])
                {
                    current = childs.top();
                    childs.pop();
                    inOrderIndex--;
                }
                BTNode *leftChild = new BTNode(postOrder[i]);
                current->left = leftChild;
                childs.push(leftChild);
            }
        }
        return root;
    }

    /*
    How It Works
    Input:
    Postorder: {9, 15, 7, 20, 3}
    Inorder: {9, 3, 15, 20, 7}
    Step-by-Step:
    Start with the last element of postorder (3) as the root.

    Push 3 onto the stack.

    Stack: [3]

    Process 20 (next in postorder):

    It doesn’t match inorder[4] (7), so it’s the right child of 3.
    Attach 20 as the right child of 3 and push it onto the stack.
    Stack: [3, 20]

    Process 7 (next in postorder):

    It doesn’t match inorder[4] (7), so it’s the right child of 20.
    Attach 7 as the right child of 20 and push it onto the stack.
    Stack: [3, 20, 7]

    Process 15 (next in postorder):

    7 matches inorder[4], so:
    Pop 7 and move inorderIndex to 3.
    20 matches inorder[3], so:
    Pop 20 and move inorderIndex to 2.
    Attach 15 as the left child of 20 and push it onto the stack.
    Stack: [3, 15]

    Process 9 (next in postorder):

    15 matches inorder[2], so:
    Pop 15 and move inorderIndex to 1.
    3 matches inorder[1], so:
    Pop 3 and move inorderIndex to 0.
    Attach 9 as the left child of 3.
    Stack: [9]

    Final Tree:
    markdown
    Copy
    Edit
            3
           / \
          9   20
             /  \
            15   7
    */
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
};

int main()
{
    BTNode bt1;
    vector<int> preOder = {9, 15, 7, 20, 3}; // Root->Left->Data
    vector<int> inOrder = {9, 3, 15, 20, 7}; // Left->Root->Data
    bt1.makeTree(preOder, inOrder);
    bt1.print();

    return 0;
}