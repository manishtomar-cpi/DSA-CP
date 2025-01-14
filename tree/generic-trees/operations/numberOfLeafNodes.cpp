#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class TreeNode
{
private:
    TreeNode *root;

    int nosOfLeafNode(TreeNode *root)
    {
        if (root == nullptr)
        {
            return -1; // edge case
        }
        if (root->childrens.size() == 0)
        {
            return 1;
        }
        int leaf = 0;

        for (int i = 0; i < root->childrens.size(); i++)
        {
            leaf += nosOfLeafNode(root->childrens[i]);
        }
        return leaf;
    }

public:
    int data;
    vector<TreeNode *> childrens;

    TreeNode(int val) : data(val), root(nullptr) {};
    TreeNode() : root(nullptr) {};

    void create()
    {
        queue<TreeNode *> childs;
        cout << "Enter data of the root node: ";
        int rootData;
        cin >> rootData;
        cout << endl;
        root = new TreeNode(rootData);
        childs.push(root);

        while (!childs.empty())
        {
            cout << "Enter the number of childs of the " << childs.front()->data << " node: ";
            int numberOfChilds;
            cin >> numberOfChilds;
            for (int i = 1; i <= numberOfChilds; i++)
            {
                cout << "Enter " << i << " child data: ";
                int childdata;
                cin >> childdata;
                cout << endl;
                // create
                TreeNode *temp = new TreeNode(childdata);
                // making connection
                childs.front()->childrens.push_back(temp);
                // push into queue
                childs.push(temp);
            }
            childs.pop();
        }
    }

    void printTree()
    {
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            cout << nodes.front()->data << ": ";
            for (int i = 0; i < nodes.front()->childrens.size(); i++)
            {
                cout << nodes.front()->childrens[i]->data << ", ";
                // pusing the childs of that node after printing the data
                nodes.push(nodes.front()->childrens[i]);
            }
            cout << endl;
            nodes.pop();
        }
    }

    int numberOfLeafNodes()
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            queue<TreeNode *> childs;
            childs.push(root);
            int leafs = 0;

            while (!childs.empty())
            {
                TreeNode *current = childs.front();
                int childSize = current->childrens.size();
                // if the current dont have any childs means the vector is empty
                if (childSize == 0)
                {
                    leafs++;
                }
                for (int i = 0; i < childSize; i++)
                {
                    childs.push(current->childrens[i]);
                }
                childs.pop();
            }
            return leafs;
        }
    }

    int getLeafNode()
    {
        return nosOfLeafNode(root);
    }
};

int main()
{
    TreeNode t1;
    t1.create();
    t1.printTree();
    cout << "Number of leaf nodes in the tree is: " << t1.getLeafNode() << endl;

    return 0;
}