#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void create(Node *&head, int arr[], int size, Node *&last)
    {
        head = new Node;
        head->data = arr[0];
        head->next = nullptr;
        last = head;
        for (int i = 1; i < size; i++)
        {
            Node *temp = new Node;
            temp->data = arr[i];
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

    void insertAtLast(Node *&head, Node *&last, int element)
    {
        Node *temp = new Node;
        temp->data = element;
        temp->next = nullptr;

        if (head == nullptr)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }
};

int main()
{
    Node *head = nullptr;
    Node *last = nullptr;

    Node n1;
    n1.insertAtLast(head, last, 0);
    n1.display(head);
    n1.insertAtLast(head, last, 1);
    n1.display(head);
    return 0;
}