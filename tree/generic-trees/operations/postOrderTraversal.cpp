#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class TreeNode
{
private:
    TreeNode *root;

    void postOrderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        for (int i = 0; i < root->childrens.size(); i++)
        {
            postOrderTraversal(root->childrens[i]);
        }

        cout << root->data << ", ";
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

    void getPostOrder()
    {
        return postOrderTraversal(root);
    }
    /*
    Algorithm:
    STEP 1: //? Push the root node into the first stack.
    STEP 2: //? Pop a node from the first stack, push it into the second stack, and push its children into the first stack.
    STEP 3: //? After processing all nodes, the second stack contains the nodes in post-order sequence.
    */
    void postOrderTraversalIterative()
    {
        if (root == nullptr)
        {
            return;
        }
        stack<TreeNode *> s1; // for childs node
        stack<TreeNode *> s2; // for post order
        // STEP 1
        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *current = s1.top();
            // STEP 2
            s2.push(s1.top());
            s1.pop();
            for (int i = 0; i < current->childrens.size(); i++)
            {
                s1.push(current->childrens[i]);
            }
        }
        // STEP 3
        while (!s2.empty())
        {
            cout << s2.top()->data << ", ";
            s2.pop();
        }
        cout << endl;
    }
};

int main()
{
    TreeNode t1;
    t1.create();
    t1.printTree();
    // t1.getPostOrder();
    t1.postOrderTraversalIterative();

    return 0;
}