#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;   // data inside node
    Node *next; // pointer to the next node, i.e it is of Node type

    void displayLL(Node *p) // take the head in the params
    {
        cout << "[ ";
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "]" << endl;
    }
};

int main()
{
    // Node *head = new Node; //creating new node
    // head->data=3; //fill data inside new created node.
    // cout << head->data << endl; //printing data

    // Node *temp; // Declares a pointer, but it doesn't point to valid memory
    //! // temp->data = 5; // This will cause undefined behavior (likely crash)

    // temp = new Node; // Now memory is allocated for a Node object
    // temp->data = 5;  // This works because `temp` points to a valid Node
    // cout << temp->data << endl;

    // delete temp; // Free the allocated memory

    //* creating linked list from array

    int A[] = {3, 4, 5, 6, 7};

    Node *head = new Node;
    Node *temp;
    Node *last;

    head->data = A[0];
    head->next = nullptr;

    last = head;
    // Crucially, since head and last originally point to the same node, updating last->next also updates head->next because they are referring to the same memory location for the first node.
    // Both head and last are pointing to the same object (the first node in the linked list).
    // Any changes made through one pointer (e.g., last->next) will also be reflected when accessed through the other pointer (head->next), because they both point to the same node.
    for (int i = 1; i < sizeof(A) / sizeof(A[0]); i++)
    {

        // creating new Node;
        temp = new Node;

        // populate new node
        temp->data = A[i];
        temp->next = nullptr;

        // last's next is pointing to temp
        last->next = temp;
        last = temp;
    }

    // display the linkedlist

    // Node *p = head;
    // cout << "[ ";
    // while (p != nullptr)
    // {
    //     cout << p->data << " ";
    //     p = p->next;
    // }
    // cout << "]" << endl;

    Node n1;
    n1.displayLL(head);

    return 0;
}