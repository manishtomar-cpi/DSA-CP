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
            cout << head->data << " ";
            head = head->next;
        }
        cout << "]" << endl;
    }
    void removeDuplicates(Node *head)
    {

        // while (head != nullptr)
        // {
        //     if (head->next == nullptr)
        //     {
        //         break;
        //     }
        //     Node *temp = new Node;
        //     if (head->data == head->next->data)
        //     {
        //         temp = head->next;
        //         head->next = head->next->next;
        //         delete temp;
        //         continue;
        //     }
        //     head = head->next;
        // }

        Node *temp = head->next;
        while (temp != nullptr)
        {
            if (head->data == temp->data)
            {
                head->next = temp->next;
                delete temp;
                temp = head->next;
            }
            else
            {
                head = temp;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    int ar[] = {3, 3, 4, 4, 4, 5, 5, 6, 6, 6, 6, 7, 8, 9, 9, 9, 10};
    int size = 17;
    Node *head = nullptr;
    Node n1;
    n1.create(head, ar, size);
    n1.display(head);
    n1.removeDuplicates(head);
    n1.display(head);

    return 0;
}