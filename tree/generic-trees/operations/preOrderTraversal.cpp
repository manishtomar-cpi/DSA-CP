#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class TreeNode
{
private:
    TreeNode *root;

    void preOrderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        { // edge case
            return;
        }
        cout << root->data << ", ";

        for (int i = 0; i < root->childrens.size(); i++)
        {

            preOrderTraversal(root->childrens[i]);
        }
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
            cout << "Hi, Enter the number of childs of the " << childs.front()->data << " node: ";
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

    void getPreOrder()
    {
        return preOrderTraversal(root);
    }

    void preOrderTraversalIterative()
    {
        if(root==nullptr){
            return;
        }
        stack<TreeNode *> childs;
        childs.push(root);

        while (!childs.empty())
        {
            TreeNode *current = childs.top();
            childs.pop();
            cout << current->data << ", ";

            for (int i = current->childrens.size() - 1; i >= 0; i--)
            {
                /*
                we are start loop from the end of the childrens vector because stack follow LIFO so that first the the first child get out
                assume the root node have 2,3,4 childs in stack ->  4,3,2 will store and first 2 comes out then same for 2 in next iteration first all childs from last to start will store
                */
                childs.push(current->childrens[i]);
            }
        }
        cout << endl;
    }
};

int main()
{
    TreeNode t1;
    t1.create();
    t1.printTree();
    // t1.getPreOrder();
    t1.preOrderTraversalIterative();

    return 0;
}