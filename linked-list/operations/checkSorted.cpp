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

    bool isSorted(Node *head)
    {
        // Node *temp = head;
        // int length = 0;
        // while (head != nullptr)
        // {
        //     length++;
        //     head = head->next;
        // }
        // for (int i = 1; i < length; i++)
        // {
        //     if ((temp->data) > (temp->next->data))
        //     {
        //         return false;
        //     }
        //     temp = temp->next;
        // }
        // return true;

        int check = INT16_MIN;
        while (head != nullptr)
        {

            if (head->data < check)
            {
                return false;
            }
            check = head->data;
            head = head->next;
        }

        return true;
    }
};

int main()
{
    int ar[] = {3, 3, 2};
    int size = 3;
    Node *head = nullptr;
    Node n1;
    n1.create(head, ar, size);
    n1.display(head);
    cout << boolalpha;
    cout << n1.isSorted(head);

    return 0;
}