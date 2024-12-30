#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void create(Node *&head, int ar[], int size)
    {
        head = new Node;
        head->data = ar[0];
        head->next = nullptr;
        Node *last = head;

        for (int i = 1; i < size; i++)
        {
            Node *temp = new Node;
            temp->data = ar[i];
            temp->next = nullptr;
            last->next = temp;
            last = temp;
        }
    }

    void display(Node *head)
    {
        cout << "[ ";
        while (head != nullptr)
        {
            cout << head->data << " -> ";
            head = head->next;
        }
        cout << "]" << endl;
    }

    void insertAtStart(Node *&head, int element)
    {
        Node *temp = new Node;
        temp->data = element;
        temp->next = head;
        head = temp;
    }

    void insertAtPos(Node *&head, int pos, int element)
    {
        if (pos == 0)
        {
            Node *temp = new Node;
            temp->data = element;
            temp->next = head;
            head = temp;
            return;
        }

        Node *temp = new Node; // for new node that will be added
        Node *current = head;  // for checking the current
        for (int i = 1; i <= pos; i++)
        {
            if (i == pos)
            {
                temp->data = element;
                temp->next = current->next; // new node now pointing to next
                current->next = temp;       // current now pointing to new node
            }
            current = current->next;
        }
    }
};
int main()
{
    int ar[] = {5, 9, 1};
    int size = 3;
    Node *head = nullptr;

    Node n1;
    // n1.create(head, ar, 3);
    // n1.display(head);

    // n1.insertAtStart(head, 4);
    // n1.display(head);
    n1.insertAtPos(head, 0, 10);
    n1.display(head);
    n1.insertAtPos(head, 1, 11);
    n1.display(head);
     n1.insertAtPos(head, 1, 12);
    n1.display(head);
    return 0;
}