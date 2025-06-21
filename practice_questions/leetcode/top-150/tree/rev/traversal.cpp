#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {};
};

class BinaryTree
{
private:
    TreeNode *root;

public:
    BinaryTree() : root(nullptr) {};

    void insert()
    {
        queue<TreeNode *> nodes;
        if (root == nullptr)
        {
            cout << "Enter root data: ";
            int val;
            cin >> val;
            root = new TreeNode(val);
            nodes.push(root);
        }

        TreeNode *left;
        TreeNode *right;
        while (!nodes.empty())
        {
            TreeNode *current = nodes.front();
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
                left = new TreeNode(leftChild);
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

                right = new TreeNode(rightChild);
                current->right = right;
                nodes.push(right);
            }
        }
    }
    void printTree()
    {
        queue<TreeNode *> childs;
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
                TreeNode *current = childs.front();
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

    void preOrderTraversal()
    {
        cout << ">>>>>>>>>>>>>>>>PRE>>>>>>>>>>>>" << endl;
        if (root == nullptr)
        {
            return;
        }
        stack<TreeNode *> st;
        TreeNode *current = root;
        while (!st.empty() || current)
        {
            while (current)
            {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            cout << current->val << " ";

            current = current->right;
        }
        cout << endl;
    }

    void inOrder()
    {
        cout << ">>>>>>>>>>>>>>>>IN>>>>>>>>>>>>" << endl;

        if (root == nullptr)
        {
            return;
        }
        TreeNode *current = root;
        stack<TreeNode *> st;
        while (!st.empty() || current)
        {
            while (current)
            {
                cout << current->val << " ";
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();
            current = current->right;
        }
        cout << endl;
    }

    void postOrder()
    {
        cout << ">>>>>>>>>>>>>>>>POST>>>>>>>>>>>>" << endl;

        stack<TreeNode *> childs;
        stack<TreeNode *> res;
        if (root == nullptr)
        {
            return;
        }
        childs.push(root);
        while (!childs.empty())
        {
            TreeNode *current = childs.top();
            childs.pop();
            res.push(current);
            if (current->left)
            {
                childs.push(current->left);
            }
            if (current->right)
            {
                childs.push(current->right);
            }
        }
        while (!res.empty())
        {
            cout << res.top()->val << " ";
            res.pop();
        }
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode *current = nodes.front();
            nodes.pop();
            TreeNode *currentLeft = nullptr;
            TreeNode *currentRight = nullptr;
            if (current->left)
            {
                currentLeft = current->left;
            }
            if (current->right)
            {
                currentRight = current->right;
            }
            if (currentLeft)
            {
                current->right = currentLeft;
                nodes.push(current->right);
            }
            if (!currentLeft)
            {
                current->right = nullptr;
            }
            if (currentRight)
            {
                current->left = currentRight;
                nodes.push(current->left);
            }
            if (!currentRight)
            {
                current->left = nullptr;
            }
        }
        return root;
    }

    TreeNode *getRoot()
    {
        return root;
    }

    void printTreeByRoot(TreeNode *root)
    {
        queue<TreeNode *> childs;
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
                TreeNode *current = childs.front();
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
};

int main()
{
    BinaryTree b1;
    b1.insert();
    b1.preOrderTraversal();
    b1.inOrder();
    b1.postOrder();
    return 0;
}