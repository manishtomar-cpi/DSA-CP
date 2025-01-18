#include <iostream>
#include <queue>
using namespace std;

class BTNode
{
private:
    BTNode *root;
    BTNode *left;
    BTNode *right;
    int data;

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
    /*
    STEP1:- push root and null into queue
    STEP2:- check null for the current
        2.1:- if(yes)-> come to next line
        2.2:- check childs not empty()
            if yes ->  push null in queue //?because which means the current level is completed
    STEP 3:- check left and right of the current and push into the queue
    //*By doing this when we encounter next null in the queue at that time all the nodes of that particular level is inside the queue because we traversed all the childs of the node at that level
    */
    void levelOrderTraversal()
    {
        queue<BTNode *> childs;
        childs.push(root);
        childs.push(nullptr); // we are putting null which indicate us to come in next line

        while (!childs.empty())
        {
            BTNode *current = childs.front();
            childs.pop();
            if (current == nullptr)
            {
                cout << endl; // now we are coming to next line current level is completed

                if (!childs.empty())
                {
                    childs.push(nullptr); // means we reach at null and the childs is not empty which means we have some level to print if null is only the pointer in the queue means we travers all nodes
                }
            }
            else
            {
                cout << current->data << " ";
                if (current->left)
                {
                    // if left of the current node is
                    childs.push(current->left);
                }
                if (current->right)
                {
                    // same with child
                    childs.push(current->right);
                }
            }
        }
    }
};

int main()
{
    BTNode bt1;
    bt1.create();
    bt1.levelOrderPrint();
    bt1.levelOrderTraversal();

    return 0;
}