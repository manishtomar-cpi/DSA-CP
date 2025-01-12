#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TreeNode
{
private:
    TreeNode *root;

public:
    int data;
    vector<TreeNode *> childrens; // for storing childs

    // constructor
    TreeNode(int val) : data(val), root(nullptr) {};
    TreeNode() : root(nullptr) {};
    void makeTree()
    {
        queue<TreeNode *> childs;
        cout << "Enter the data in Root node: ";
        int rootData;
        cin >> rootData;
        root = new TreeNode(rootData);
        childs.push(root);

        while (!childs.empty())
        {
            cout << "Enter the number of childs of " << childs.front()->data << " :";
            int numberOfChilds;
            cin >> numberOfChilds;
            cout << endl;
            for (int i = 1; i <= numberOfChilds; i++)
            {
                cout << "Enter " << i << " child of the node " << childs.front()->data << " :";
                int childData;
                cin >> childData;
                // create new node
                TreeNode *temp = new TreeNode(childData);

                // making connection with parent
                childs.front()->childrens.push_back(temp);

                // push into the childs queue
                childs.push(temp);
            }
            // removing the front after using it
            childs.pop();
        }
    }

    void printTree()
    {
        queue<TreeNode *> childs;
        childs.push(root);

        while (!childs.empty())
        {
            cout << childs.front()->data << ": ";
            for (int i = 0; i < childs.front()->childrens.size(); i++)
            {
                cout << childs.front()->childrens[i]->data << ", ";
                childs.push(childs.front()->childrens[i]);
            }
            childs.pop();
            cout << endl;
        }
    }

    int countNodes()
    {
        int totalNodes = 0;
        queue<TreeNode *> childs;
        if (!root)
        {
            return 0;
        }
        else
        {
            childs.push(root);
            totalNodes++;
            while (!childs.empty())
            {
                for (int i = 0; i < childs.front()->childrens.size(); i++)
                {
                    totalNodes++;
                    childs.push(childs.front()->childrens[i]);
                }
                childs.pop();
            }
            return totalNodes;
        }
    }
};

int main()
{
    TreeNode t1;

    t1.makeTree();
    t1.printTree();
    cout << "total numbers of nodes on the tree is: " << t1.countNodes() << endl;

    return 0;
}