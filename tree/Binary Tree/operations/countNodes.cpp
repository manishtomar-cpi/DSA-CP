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

    int totalNumOfNode(BTNode *root)
    {

        if (root == nullptr)
        {
            return 0;
        }
        int totalLeftNodes = totalNumOfNode(root->left);
        int totalRightnodes = totalNumOfNode(root->right);

        return totalLeftNodes + totalRightnodes + 1;
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
     we will traverse each node and if they have left right accordingly ++ nodes and storing in the queue;
    */
    int totalNodes()
    {
        // queue<BTNode *> childs;
        // childs.push(root);
        // int nodes = 0;
        // while (!childs.empty())
        // {
        //     BTNode *current = childs.front();
        //     childs.pop();
        //     if (current->left)
        //     {
        //         nodes++;
        //         childs.push(current->left);
        //     }
        //     if (current->right)
        //     {
        //         nodes++;
        //         childs.push(current->right);
        //     }
        // }

        // return nodes + 1; //? why + 1 because we left root for root we did +1;
        return totalNumOfNode(root);
    }
};

int main()
{
    BTNode bt1;
    bt1.create();
    bt1.levelOrderPrint();
    cout << "Total nodes in our tree is: " << bt1.totalNodes() << endl;

    return 0;
}