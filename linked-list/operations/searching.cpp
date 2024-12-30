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
    bool search(Node *&head, int element)
    {
        while (head != nullptr)
        {
            if (head->data == element)
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }

    bool improvedSearch(Node *&head, int element)
    {
        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr)
        {
            if (element == current->data)
            {                               // if found
                prev->next = current->next; // if found we are moving the found one to start for that the prev is pointing to current next
                current->next = head;       // now current is pointing nto the start
                head = current;             // finally, start became current
                return true;
            }
            else
            {
                prev = current;          // because prev is followinf current
                current = current->next; // now current is going to next
            }
        }
    }
};

int main()
{
    int arr[] = {2, 5, 6, 1, 8, 9, 10, 7};
    Node *head = nullptr;
    int size = 8;

    Node n1;
    n1.create(head, arr, size);
    n1.display(head);
    cout << boolalpha;
    // cout << n1.search(head, 18);
    cout << n1.improvedSearch(head, 8) << endl;
    n1.display(head);
    cout << n1.improvedSearch(head, 10) << endl;
    n1.display(head);

    return 0;
}