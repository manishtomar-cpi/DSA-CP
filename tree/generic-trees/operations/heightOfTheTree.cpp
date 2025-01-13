#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
private:
    TreeNode *root;

public:
    int data;
    vector<TreeNode *> childrens;

    TreeNode(int val) : data(val), root(nullptr) {};
    TreeNode() : root(nullptr) {};

    void maketree()
    {
        queue<TreeNode *> childs;
        cout << "Enter the data of the root node: ";
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
            cout << endl;

            for (int i = 1; i <= numberOfChilds; i++)
            {
                cout << "Enter the data of the " << i << " child: ";
                int childData;
                cin >> childData;
                // create
                TreeNode *temp = new TreeNode(childData);
                // make connection
                childs.front()->childrens.push_back(temp);
                // push into queue
                childs.push(temp);
            }
            // removing the created one
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

    int treeHeight()
    {
        queue<TreeNode *> childs;
        childs.push(root);
        int height = 0;
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            // the logic is first we will travers each level then increase height
            while (!childs.empty())
            {
                int levelSize = childs.size(); // taking level size

                // iterate all the roots of that level
                for (int i = 0; i < levelSize; i++)
                {
                    TreeNode *current = childs.front();
                    childs.pop();
                    // iterate over all the childs of that root
                    for (int j = 0; j < current->childrens.size(); j++)
                    {
                        childs.push(current->childrens[j]);
                    }
                }
                // after treversing the complete level increase height
                height++;
            }

            return height;
        }
    }
};

int main()
{
    TreeNode t1;

    t1.maketree();
    t1.printTree();
    cout << "height of the tree is: " << t1.treeHeight() << endl;

    return 0;
}