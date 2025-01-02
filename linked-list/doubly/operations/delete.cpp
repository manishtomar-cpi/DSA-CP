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

    void deleteNode(int pos)
    {
        cout << "======AFTER DELETING======" << endl;

        if (pos <= 0)
        {
            return;
        }
        Node *temp = head;
        if (pos == 1)
        {
            if (temp->next == nullptr)
            {
                head = temp->next;
                delete temp;
                tail = head;
            }
            else
            {
                head = temp->next;
                temp->next->prev = nullptr;
                delete temp;
            }
        }
        else
        {
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            if (temp->next == nullptr)
            {
                // means we are deleting last
                temp->prev->next = nullptr;
                tail = temp->prev;
                delete temp;
            }
            else
            {
                // means b/w
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
            }
        }
    }
};

int main()
{
    int arr[] = {2};
    int size = sizeof(arr) / sizeof(arr[0]);

    DoublyLL list1;
    list1.create(arr, size);
    list1.display();

    list1.deleteNode(1);
    list1.display();
    list1.displayByTail();
    return 0;
}