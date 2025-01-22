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
        Algorithm Steps:
    Initialize:
    Create the root node from the first element in the preorder array.
    Push the root node onto a stack.
    Set inorderIndex to 0 to keep track of the current position in the inorder array.
    
    Iterate through Preorder:
    Start from the second element of the preorder array and process each node:
    Let the current node be the next element in preorder.

    Check the Stack's Top:
    Compare the top node of the stack with the current value in the inorder array (inorder[inorderIndex]):
    Case 1: If the stack's top does not match the inorder value:
    The current node is the left child of the top node.
    Create the node, attach it as the left child, and push it onto the stack.
    Case 2: If the stack's top matches the inorder value:
    Pop nodes from the stack until the stack is empty or the top no longer matches the inorder value.
    Move inorderIndex forward for each popped node.
    Attach the current node as the right child of the last popped node.
    Push the current node onto the stack.

    Repeat:
    Continue this process until all nodes in the preorder array are processed.
    Tree Complete:
    Once the preorder array is fully processed, the binary tree is complete.

    */
    BTNode *makeTree(vector<int> preOrder, vector<int> inOrder)
    {
        // will use preorder nods to making tree inorder helps us to move from left to right childs
        stack<BTNode *> nodes;
        int inOrderIndex = 0;
        root = new BTNode(preOrder[0]); // because first node of the pre order should the root node
        nodes.push(root);               // push root to the stack
        for (int i = 1; i < preOrder.size(); i++)
        {
            BTNode *current = nodes.top();
            // if the top of the stack is not equal to the inderOrder[index] means still left childs of that node is remaining
            if (current->data != inOrder[inOrderIndex])
            {
                BTNode *leftNode = new BTNode(preOrder[i]);
                current->left = leftNode;
                nodes.push(current->left);
            }
            else
            {
                while (!nodes.empty() && nodes.top()->data == inOrder[inOrderIndex])
                { // why this condition because when the current not equal to the preOrder[i] node whuch means all let childs of current is processed now we need to find the new node that will processed and the right childs of that node will the preOrder[i]
                    current = nodes.top();
                    nodes.pop();
                    inOrderIndex++; // because that node in the inorder is processed now check for nect one
                }
                // now the current node is that node whome all the left childs have processed and the preOrder[i] is the right child of that node
                BTNode *rightNode = new BTNode(preOrder[i]);
                current->right = rightNode;
                // after creating push into stack because we also take care of the left and right of that node
                nodes.push(current->right);
            }
        }
        return root;
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
};

int main()
{
    BTNode bt1;
    vector<int> preOder = {3, 9, 20, 15, 7}; // Root->Left->Data
    vector<int> inOrder = {9, 3, 15, 20, 7}; // Left->Root->Data
    bt1.makeTree(preOder, inOrder);
    bt1.print();

    return 0;
}