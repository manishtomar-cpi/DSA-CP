#include <iostream>
#include <vector>
#include <stack>
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

    void deleteTree()
    {
        if (root == nullptr)
        {
            return;
        }
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;

        s1.push(root);
        while (!s1.empty())
        {
            TreeNode *current = s1.top();
            s1.pop();
            s2.push(current);
            for (int i = 0; i < current->childrens.size(); i++)
            {
                s1.push(current->childrens[i]);
            }
        }
        // post order travral
        while (!s2.empty())
        {
            TreeNode *temp = s2.top();
            delete temp;
            cout << s2.top()->data << " deleted!" << endl;
            s2.pop();
        }
        /*
       The delete operator deallocates the memory for the object but does not reset the pointer to nullptr.
       After calling delete root, the root pointer will still contain the memory address where the object was previously allocated. This is now invalid memory (dangling pointer).
       Accessing root after deleting it can cause undefined behavior.
       How delete Works:
       When use delete on a pointer:
       The memory that the pointer refers to is deallocated (freed)
       The pointer itself is not modified. It still holds the memory address that was previously allocated, even though that memory is now invalid (a dangling pointer).
       So, after delete, the pointer still exists and points to the same location in memory, but that location is now undefined (no longer valid).
       If we try to access or dereference the pointer, we will encounter undefined behavior.
       */
        root = nullptr;
    }
};

int main()
{
    TreeNode t1;

    t1.maketree();
    t1.printTree();
    t1.deleteTree();

    return 0;
}