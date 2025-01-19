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
    L,R,D (left, right, data)
    STEP1: take two stacks one for childs second for ordering the post order
    STEP2: push the root into childs
    STEP3: pop the top from childs and push into result
    STEP4: if top have left push left into childs, if right then push into it on childs
    STEP5: repeat step 3 and 4 until childs became empty
    STEP6: now the result have the post order traversal
        4
       / \
      2   6
     / \
    1   3
The traversal will visit nodes in the following order:

Postorder Sequence:
1, 3, 2, 6, 4

*/

    void getPostOrder()
    {
        // step 1
        stack<BTNode *> childs;
        stack<BTNode *> result;
        // step 2
        childs.push(root);
        while (!childs.empty())
        { // step 5
            BTNode *current = childs.top();
            // step 3
            childs.pop();
            result.push(current);
            // step 4
            if (current->left)
            {
                childs.push(current->left);
            }
            if (current->right)
            {
                childs.push(current->right);
            }
        }
        while (!result.empty())
        { // step 6
            cout << result.top()->data << ", ";
            result.pop();
        }
    }
};

int main()
{
    BTNode bt1;
    bt1.create();
    bt1.print();
    bt1.getPostOrder();
    return 0;
}
