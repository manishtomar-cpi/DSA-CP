#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int data) : val(data), left(nullptr), right(nullptr), next(nullptr) {};
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {};
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {};

    void insert()
    {
        queue<Node *> nodes;
        if (root == nullptr)
        {
            cout << "Enter root data: ";
            int val;
            cin >> val;
            root = new Node(val);
            nodes.push(root);
        }

        Node *left;
        Node *right;
        while (!nodes.empty())
        {
            Node *current = nodes.front();
            nodes.pop();
            cout << "Enter left child of " << current->val << " : ";
            int leftChild;
            cin >> leftChild;
            if (leftChild == -1)
            {
                current->left = nullptr;
            }
            else
            {
                left = new Node(leftChild);
                current->left = left;
                nodes.push(left);
            }
            cout << "Enter right child of " << current->val << " : ";
            int rightChild;
            cin >> rightChild;
            if (rightChild == -1)
            {
                current->right = nullptr;
            }
            else
            {

                right = new Node(rightChild);
                current->right = right;
                nodes.push(right);
            }
        }
    }
    void printTree()
    {
        queue<Node *> childs;
        if (root == nullptr)
        {
            cout << "empty!" << endl;
            return;
        }
        else
        {
            childs.push(root);
            while (!childs.empty())
            {
                Node *current = childs.front();
                childs.pop();
                cout << current->val << " :";
                if (current->left)
                {
                    cout << " L: " << current->left->val;
                    childs.push(current->left);
                }
                if (current->right)
                {
                    cout << " R: " << current->right->val;
                    childs.push(current->right);
                }
                cout << endl;
            }
        }
    }

    Node *getRoot()
    {
        return root;
    }

    void printTreeByRoot(Node *root)
    {
        queue<Node *> childs;
        if (root == nullptr)
        {
            cout << "empty!" << endl;
            return;
        }
        else
        {
            childs.push(root);
            while (!childs.empty())
            {
                Node *current = childs.front();
                childs.pop();
                cout << current->val << " :";
                if (current->left)
                {
                    cout << " L: " << current->left->val;
                    childs.push(current->left);
                }
                if (current->right)
                {
                    cout << " R: " << current->right->val;
                    childs.push(current->right);
                }
                if (current->next)
                {
                    cout << " next: " << current->next->val;
                }
                if (!current->next)
                {
                    cout << " next: null ";
                }
                cout << endl;
            }
        }
    }

    /*
    Approach: Connect Next Right Pointers in Each Node (No Extra Space)

    1. Edge Case:
       - If the root is NULL, return NULL immediately.

    2. Initialize:
       - Let 'current' be the pointer to the current level's node we're processing.
       - Start from the root.

    3. Outer While Loop:
       - Traverse level by level using the already established `next` pointers.

    4. Create a Dummy Node:
       - At each level, create a dummy node to help link the next level nodes.
       - 'tail' points to the last node we've connected at the next level.

    5. Inner While Loop:
       - Traverse the current level using `current`.
       - For each node:
         - If it has a left child:
             - Set `tail->next = current->left`
             - Move `tail = tail->next`
         - If it has a right child:
             - Set `tail->next = current->right`
             - Move `tail = tail->next`
         - Move `current = current->next` to go to the next node in the current level.

    6. Move to Next Level:
       - After the inner loop ends, move `current = dummy->next`
       - This takes us to the leftmost node of the next level.

    7. Repeat:
       - Repeat the process until there are no more levels to process.

    8. Return:
       - Finally, return the original root which now has `next` pointers populated level-wise.

    Benefits:
    - No queue or stack is used.
    - The space complexity is O(1), and time is O(n).


    Example Tree:
            1
          /   \
         2     3
        / \     \
       4   5     7

    Goal: Connect next right pointers at each level to form a linked list.

    After connection, the 'next' pointers should form:
    Level 1: 1 -> NULL
    Level 2: 2 -> 3 -> NULL
    Level 3: 4 -> 5 -> 7 -> NULL

    1. We start at the root node.

    2. For each level:
       - Use a dummy node (like a head of a linked list) to collect all children of the current level.
       - Use a 'tail' pointer to keep adding left and right children of nodes.
       - Traverse the current level using the already connected 'next' pointers.
       - Move to the next level by setting current = dummy->next.

    3. Repeat until there are no more levels (i.e., current == nullptr).

    Visualization:

    Level 1:
    [1] -> NULL

    → dummy = new Node()
    → tail = dummy
    → 1 has left (2), so tail->next = 2, tail = 2
    → 1 has right (3), so tail->next = 3, tail = 3
    → dummy->next = 2 → this becomes the head of next level

    Level 2:
    [2] -> [3] -> NULL

    → dummy = new Node()
    → tail = dummy
    → 2 has left (4), tail->next = 4, tail = 4
    → 2 has right (5), tail->next = 5, tail = 5
    → 3 has right (7), tail->next = 7, tail = 7
    → dummy->next = 4 → head of next level

    Level 3:
    [4] -> [5] -> [7] -> NULL
    → no more children, done!

    This method uses no queue or additional data structures — only existing next pointers and a few pointers (constant space).
    */

    Node *connect()
    {
        //? edge case
        if (root == nullptr)
        {
            return nullptr;
        }
        // queue<Node *> nodes;
        // nodes.push(root);
        // nodes.push(nullptr);
        // while (!nodes.empty())
        // {
        //     Node *current = nodes.front();
        //     nodes.pop();
        //     if (current == nullptr)
        //     {
        //         if (!nodes.empty())
        //         {
        //             nodes.push(nullptr);
        //             continue;
        //         }
        //     }
        //     else
        //     {
        //         current->next = nodes.front();
        //         if (current->left)
        //         {
        //             nodes.push(current->left);
        //         }
        //         if (current->right)
        //         {
        //             nodes.push(current->right);
        //         }
        //     }
        // }

        //! Without using queue
        Node *current = root;
        while (current)
        {
            Node *dummy = new Node();
            Node *tail = dummy;
            while (current)
            {
                if (current->left)
                {
                    tail->next = current->left;
                    tail = tail->next;
                }
                if (current->right)
                {
                    tail->next = current->right;
                    tail = tail->next;
                }
                current = current->next;
            }
            tail->next = nullptr;
            current = dummy->next;
        }
        return root;
    }
};

int main()
{
    BinaryTree b1;
    b1.insert();
    b1.connect();
    b1.printTreeByRoot(b1.getRoot());
    return 0;
}