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

    void insertAtSorted(Node *head, int element)
    {
        Node *temp = new Node;
        Node *previous = nullptr;
        temp->data = element;
        temp->next = nullptr;

        while (head != nullptr)
        {
            if (head->data < element)
            {
                previous = head;
            }
            else
            {
                break;
            }
            head = head->next;
        }
        previous->next = temp;
        temp->next = head;
    }
};

int main()
{
    int arr[] = {1, 2, 4, 6};
    Node *head = nullptr;
    int size = 4;

    Node n1;
    n1.create(head, arr, size);
    n1.display(head);

    n1.insertAtSorted(head, 3);
    n1.display(head);
    n1.insertAtSorted(head, 5);
    n1.display(head);
    n1.insertAtSorted(head, 5);
    n1.display(head);

    return 0;
}