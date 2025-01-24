#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class BTNode
{
private:
    BTNode *root;
    BTNode *left;
    BTNode *right;
    int data;

    void inOrder(BTNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inOrder(root->left);
        cout << root->data << ", ";
        inOrder(root->right);
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

    void print()
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
        Initialization:
        Start with the root node.
        Use a stack to traverse the tree and a vector (path) to track the current path.

        Traverse the Tree:
        Push nodes onto the stack and add them to the path as you move left.
        If the current node matches the target, return the path.

        Backtracking:
        If there are no unvisited right children:
        Pop the current node from the stack.
        Remove it from the path.
        Mark the node as visited and backtrack to its parent.
        Right Subtree:

        If a right child exists and hasn’t been visited, move to the right child.
        Repeat:

        Continue until the stack is empty or the target node is found.
        Input Tree:

            1
           / \
          2   3
         / \  / \
        4   5 6  7
    Target: 5
    Execution:

    Iteration 1:
    Current Node: 1.
    Stack: [1].
    Path: [1].

    Iteration 2:
    Move to Left Child: 2.
    Stack: [1, 2].
    Path: [1, 2].

    Iteration 3:
    Move to Left Child: 4.
    Stack: [1, 2, 4].
    Path: [1, 2, 4].

    Backtrack:
    Pop 4 (no right child).
    Stack: [1, 2].
    Path: [1, 2].
    Move to Right Child:

    Current Node: 5.
    Stack: [1, 2, 5].
    Path: [1, 2, 5].
    Target Found: Return [1, 2, 5].

    Output:
    Path to node 5: 1 2 5

    */
    bool getPath(int val, vector<int> &vec)
    {
        stack<BTNode *> childs;
        BTNode *current = root;
        BTNode *lastVisited = nullptr; // this helps us to traverse the right subtree only once

        while (current || !childs.empty())
        {
            while (current)
            {
                // traverse the left subtree
                childs.push(current);
                vec.push_back(current->data);
                if (current->data == val)
                {
                    return true;
                }
                current = current->left;
            }
            current = childs.top();

            // if the current have right subtree
            if (current->right && current->right != lastVisited)
            {
                // traverse the right subtree
                current = current->right;
            }
            else
            {
                // backtracking
                childs.pop();
                vec.pop_back();
                lastVisited = current;
                current = nullptr;
            }
        }
    }
};

int main()
{
    BTNode bt1;
    bt1.create();
    bt1.print();
    vector<int> vec;
    if (bt1.getPath(9, vec))
    {
        cout << "[ ";
        for (auto i : vec)
        {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
