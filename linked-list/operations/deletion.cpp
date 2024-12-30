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

    void deleteNode(Node *&head, int pos)
    {
        if (pos == 1) // checking if the params is first node
        {
            Node *temp = head;
            head = head->next; // move head to next
            delete temp;       // delete first
        }
        else
        {
            Node *temp = head;    // for current
            Node *prev = nullptr; // for prev
            for (int i = 1; i < pos; i++)
            { // going towards the pos
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
        }
    }
};
int main()
{
    int ar[] = {5, 9, 1, 6, 7, 8};
    int size = 6;
    Node *head = nullptr;

    Node n1;
    n1.create(head, ar, size);
    n1.display(head);

    n1.deleteNode(head, 1);
    n1.display(head);
    n1.deleteNode(head, 2);
    n1.display(head);
    return 0;
}