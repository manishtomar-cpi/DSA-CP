#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev; // store the prev one
    int data;
    Node *next;

    Node(int val) : prev(nullptr), data(val), next(nullptr) {};
};

class DoublyLL
{
private:
    Node *head;
    Node *tail; // storing the last node for printing by last

public:
    DoublyLL() : head(nullptr) {};

    void create(int arr[], int size)
    {
        head = new Node(arr[0]);
        Node *last = head;

        for (int i = 1; i < size; i++)
        {
            Node *temp = new Node(arr[i]);
            temp->prev = last;
            last->next = temp;
            last = temp;
        }
        tail = last;
    }

    void display()
    {
        cout << "======BY HEAD======" << endl;

        Node *temp = head;

        cout << "[ ";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "(null) ]" << endl;
    }

    void displayByTail()
    {
        cout << "======BY TAIL======" << endl;

        Node *temp = tail;
        cout << "[ ";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "(null) ]" << endl;
    }

    void insert(int pos, int data)
    {
        if (pos < 0)
        {
            return;
        }

        Node *p = new Node(data);
        if (pos == 0)
        {
            if (head == nullptr) // If the list is empty
            {
                head = p;
                tail = p;
            }
            else
            { // we need to modify the head as well
                p->next = head;
                head->prev = p;
                head = p;
            }
            return;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            if (temp->next == nullptr) // means we are inserting at the end
            {
                p->next = temp->next;
                p->prev = temp;
                temp->next = p;
                tail = p;
            }
            else // means we are inserting b/w start and end
            {
                p->next = temp->next;
                p->prev = temp;
                temp->next = p;
                p->next->prev = p;
            }
        }
    }
};

int main()
{
    int arr[] = {2, 4, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    DoublyLL list1;
    list1.create(arr, size);

    list1.display();
    list1.displayByTail();

    list1.insert(4, 9);

    list1.display();
    list1.displayByTail();
    return 0;
}