#include <iostream>
#include <queue>
using namespace std;

class BTNode
{

    BTNode *root;
    BTNode *left;
    BTNode *right;
    void recursivePrint(BTNode *root)
    {
        if (root == nullptr)
        { // base case
            return;
        }
        cout << root->data << ": "; // print root
        if (root->left != nullptr)
        {
            cout << "L:" << root->left->data; // left
        }
        if (root->right != nullptr)
        {
            cout << " R:" << root->right->data; // right
        }

        cout << endl;
        recursivePrint(root->left);  // first on left side
        recursivePrint(root->right); // then right side
    }

public:
    int data;

    BTNode(int val) : data(val), right(nullptr), left(nullptr), root(nullptr) {};
    BTNode() : root(nullptr), left(nullptr), right(nullptr) {};
    void create(int val)
    {
        root = new BTNode(val);
        BTNode *temp1 = new BTNode(2);
        BTNode *temp2 = new BTNode(3);

        root->left = temp1;
        root->right = temp2;
    }

    void getRecursivePrint()
    {
        recursivePrint(root);
    }

    void createBTLevelWise()
    {
        queue<BTNode *> childs;
        cout << "Enter root data: ";
        int rootData;
        cin >> rootData;
        cout << endl;
        root = new BTNode(rootData);
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

    void levelOrderPrint()
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

    void levelOrderTraversal()
    {
        if (root == nullptr)
        {
            return;
        }
        queue<BTNode *> childs;
        childs.push(root);
        while (!childs.empty())
        {
            BTNode *current = childs.front();
            childs.pop();
            cout << current->data << ", ";
            if (current->left)
            {
                childs.push(current->left);
            }
            if (current->right)
            {
                childs.push(current->right);
            }
        }
        cout << endl;
    }

    ~BTNode()
    {
        delete left; // this is c which will first go in the depth thne delete left right then root
        delete right;
    }
};

int main()
{
    BTNode bt1;
    // bt1.create(1);
    bt1.createBTLevelWise();
    bt1.getRecursivePrint();
    bt1.levelOrderPrint();
    cout << "level order traversal: ";
    bt1.levelOrderTraversal();
    cout << endl;
    return 0;
}