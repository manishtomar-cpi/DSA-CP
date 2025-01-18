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

    void getInorder()
    {
        /*
        Start at the root node.
        Push all the left children of the current node onto the stack until you reach a nullptr.
        Pop a node from the stack, visit it, and move to its right child.
        Repeat steps 2 and 3 until the stack is empty and the current node is nullptr.
        */
        stack<BTNode *> st;
        BTNode *current = root;

        while (current != nullptr || !st.empty())
        //? loop run when both of the conditions true because when both the conditions true means we trave whole tree
        {

            while (current != nullptr)
            { //? runs only when we come to that node which have left sub tree
                st.push(current);
                current = current->left;
            }
            // means we are at the leaf node of the left subtree
            current = st.top();
            st.pop();
            cout << current->data << ", ";
            // now print the right sub tree
            current = current->right;
        }
    }
};

int main()
{
    BTNode bt1;
    bt1.create();
    bt1.print();
    bt1.getInorder();
    return 0;
}