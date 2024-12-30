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

    int maxElement(Node *head)
    {
        int max = head->data;
        while (head != nullptr)
        {
            if (head->data > max)
            {
                max = head->data;
            }
            head = head->next;
        }
        return max;
    }

    int maxRec(Node *head)
    {
        int max = 0;
        if (head == nullptr)
        {
            return INT16_MIN;
        }
        max = maxRec(head->next);
        // if (max > head->data)
        // {
        //     return max;
        // }
        // else
        // {
        //     return head->data;
        // }
        return max > head->data ? max : head->data;
    }
};

int main()
{
    int ar[] = {5, 9, 1, 4, 8, 7, 10, 11, 12};
    int size = 9;
    Node *head = nullptr;

    Node n1;
    n1.create(head, ar, 9);
    n1.display(head);
    //  cout << "maximum element in the ll is: " << n1.maxElement(head) << endl;
    cout << "maximum element in the ll is: " << n1.maxRec(head) << endl;

    return 0;
}