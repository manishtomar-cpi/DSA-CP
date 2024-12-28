#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void display(Node *p)
    {
        cout << "[ ";
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "]" << endl;
    }

    void addElement(Node *&last, int data)
    {
        Node *temp = new Node; // Create a new node internally
        temp->data = data;     // Fill the data
        temp->next = nullptr;  // Set the next pointer
        last->next = temp;     // Link the new node
        last = temp;           // Update the last pointer
    }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    Node *head = new Node;
    head->data = a[0];
    head->next = nullptr;

    Node *temp;
    Node *last;

    last = head; // now first and last is same

    for (int i = 1; i < sizeof(a) / sizeof(a[0]); i++)
    {
        temp = new Node;
        temp->data = a[i];
        temp->next = nullptr;
        last->next = temp;

        last = temp;
    }

    Node n1;
    n1.display(head);
    // cout << "checking last..." << endl;
    // cout << last->next << endl;

    // Node *Add = new Node;
    // Add->data = 6;
    // Add->next = nullptr;
    // last->next = Add;
    // last = Add;

    // cout << "After Add" << endl;

    // n1.display(head);

    n1.addElement(last, 6);
    n1.display(head);

    n1.addElement(last, 7);
    n1.display(head);

    return 0;
}