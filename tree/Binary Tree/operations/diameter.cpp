#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
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

    int diameter()
    {
        stack<BTNode *> childs;
        unordered_map<BTNode *, int> height;
        BTNode *current = root;
        int diameter = 0;
        BTNode *lastVisited = nullptr; // hepls us to go in max depth of the tree

        while (!childs.empty() || current)
        {

            while (current)
            { // means we need to do in left depth
                childs.push(current);
                current = current->left;
            }
            current = childs.top();
            if (!current->right || current->right == lastVisited)
            {
                childs.pop();
                int leftHeight = height[current->left];             // compute left height from hashmap
                int rightHeight = height[current->right];           // compute right height form the hashmap
                height[current] = 1 + max(leftHeight , rightHeight);   // calculate the current node height
                diameter = max(diameter, leftHeight + rightHeight); // diameter at this step is maximum of current diameter and sum of left sybtree's height and right subtree's height
                lastVisited = current;                              // hepls us make sure that the right subtree of that particular node is calculated
                current = nullptr;                                  // because we dont want to calculate it again
            }
            else
            {
                current = current->right; // now the time to go in more depth of the current node
            }
        }
        return diameter;
    }
  
};

int main()
{
    BTNode bt1;
    bt1.create();
    bt1.print();
    cout << bt1.diameter() << endl;
    return 0;
}

