#include <iostream>
#include <vector>
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

    void reversing(Node *head)
    {
        Node *temp = head;
        vector<int> vec;
        int i = 0;
        while (head != nullptr)
        {
            vec.push_back(head->data);
            head = head->next;
        }
        i = vec.size() - 1;
        while (i >= 0)
        {
            temp->data = vec[i];
            i--;
            temp = temp->next;
        }
    }

    void reversingByNodes(Node *&head)
    {
        Node *first = head;     // for storing the next node address
        Node *second = nullptr; // for reversing
        Node *third = nullptr;

        while (first != nullptr)
        {
            third = second;
            second = first;
            first = first->next;
            second->next = third;
        }
        head = second;
    }
};

int main()
{
    int ar[] = {10, 20, 30, 40, 50};
    int size = 5;
    Node *head = nullptr;
    Node n1;
    n1.create(head, ar, size);
    n1.display(head);

    n1.reversing(head);
    n1.display(head);

    n1.reversingByNodes(head);
    n1.display(head);

    return 0;
}