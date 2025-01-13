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
    int nodesAtLevel(int k)
    {
        if (root == nullptr || k > treeHeight())
        { // if tree is empty or the value of k is greatorn then the total level in the tree

            return -1;
        }
        else
        {
            if (k == 1) // on root only 1 node
            {
                return k;
            }
            else if (k == 2) // at level 2 all the childs of the root are present
            {
                return root->childrens.size();
            }
            else
            {
                int a = 0;
                queue<TreeNode *> childs;
                childs.push(root);
                while (a < k - 1) // why (a<k-1) ? because if we want level 3 we will take only 2 iteration to store all nodes at level 3 into the queue (0 & 1 only)
                {
                    int levelSize = childs.size();
                    for (int i = 0; i < levelSize; i++)
                    {//this loop run on each root of that level
                        TreeNode *current = childs.front();

                        childs.pop();//after storing in current we are removing the first node in the queue
                        for (int j = 0; j < current->childrens.size(); j++)
                        {//this loop store all the chils node at that level
                            childs.push(current->childrens[j]);
                        }
                    }
                    a++;
                }
                return childs.size(); //now the queue have the total nodes at the level k 
            }
        }
    }
};

int main()
{
    TreeNode t1;

    t1.maketree();
    t1.printTree();
    // cout << "height of the tree is: " << t1.treeHeight() << endl;
    int k = 4;
    cout << "nodes at level " << k << " is: " << t1.nodesAtLevel(k) << endl;

    return 0;
}