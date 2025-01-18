#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode
{
private:
    TreeNode *root; // root node of the tree

public:
    int data;                    // the data inside tree's node
    vector<TreeNode *> children; // this vector will used for storing the address of the child nodes of the particular root node

    // constructor
    TreeNode() : root(nullptr) {};
    TreeNode(int data) : data(data), root(nullptr) {};

    /*
       in this function we are taking the queue that queue will store the nodes and helps us for making childs(taking input) level wise
       then first we will create the root node, then we will push root node to the queue
       the  will start the while loop in which first we will store that node and remove from queue because in the next iteration we have the first child of that node
       then we will run the for loop based on the number iof childs of that node and follow three steps
       1- making new Node(child)
       2-store to the current node child vector
       3- push to the queue that newly generated child
       */

    TreeNode *makeTreeLevelWise()
    {
        queue<TreeNode *> nodes; // here we are taking queue for storing the nodes

        // making root
        int rootData;
        cout << "Enter root data: ";
        cin >> rootData;
        cout << endl;
        root = new TreeNode(rootData);
        // push root to the queue for taking childs
        nodes.push(root);

        // while loop for taking childs of root
        while (!nodes.empty())
        {
            TreeNode *temp = nodes.front(); // we are taking the first node in the queue for making childs of that node
            nodes.pop();                    // after storing removing the front node from queue
            cout << "Enter number of childs of node " << temp->data << ": ";
            int n;
            cin >> n;
            cout << endl;
            // for loop helps us for making the childs of that node
            for (int i = 1; i <= n; i++)
            {
                cout << "Enter the " << i << " child of the node " << temp->data << ": ";
                int childData;
                cin >> childData;
                cout << endl;
                // !STEP: 1- creating child
                TreeNode *child = new TreeNode(childData);
                // !STEP 2- push to that queue for again taking childs of that new generated node
                nodes.push(child);
                // !STEP 3- making connection with parent, parent is in temp;
                temp->children.push_back(child);
            }
        }

        return root;
    }

    void printTree(TreeNode *root)
    {
        if (root == nullptr)
        { // edge case -> if not don't have anything //!this is not base case for recursion, base case here is the leaf nodes (the size of the childs vector)
            return;
        } // this function is taking the root node pointer then it will able to print data on the location
        cout << root->data << ": "; // first we are printing the root's data
        for (int i = 0; i < root->children.size(); i++)
        { // then we are printing the all child of that node
            cout << root->children[i]->data << ", ";
        }
        cout << endl;

        for (int i = 0; i < root->children.size(); i++)
        { // calling recursion on each node now
            printTree(root->children[i]);
        }
    }

    void printTreeLevelWise()
    {
        // we are taking queue to store nodes same as making tree
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            cout << nodes.front()->data << ": "; // printing the root node
            for (int i = 0; i < nodes.front()->children.size(); i++)
            {
                // printing the childs of the nodes
                cout << nodes.front()->children[i]->data << ", ";
                // push the child inside the queue
                nodes.push(nodes.front()->children[i]);
            }
            // removing the current one from queue because we done with that
            nodes.pop();
            cout << endl;
        }
    }
};

int main()
{
    // TreeNode *root = new TreeNode(1); // root node
    // TreeNode *n1 = new TreeNode(2);
    // TreeNode *n2 = new TreeNode(3);

    // root->children.push_back(n1); // n1 is now child of root
    // root->children.push_back(n2); // n2 too
    TreeNode t1;
    t1.makeTreeLevelWise();
    // t1.printTree(root);
    t1.printTreeLevelWise();

    return 0;
}