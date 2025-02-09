#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {};
};

class CircularLL
{
private:
    Node *head;

public:
    CircularLL() : head(nullptr) {};

    void create(int arr[], int size)
    {
        head = new Node(arr[0]);
        Node *last = head;
        for (int i = 1; i < size; i++)
        {
            Node *temp = new Node(arr[i]);
            last->next = temp;
            last = temp;
        }
        last->next = head;
    }

    void display()
    {

        if (head == nullptr)
            return; // means list is empty
        Node *temp = head;
        cout << "[ ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)]" << endl;
    }

    void insert(int pos, int data)
    {
        if (pos < 0)
        {
            return;
        }
        Node *temp = head;
        Node *p = nullptr;
        if (pos == 0)
        { // if insert before head
            if (head == nullptr)
            { // if it was the first element of the ll
                temp = new Node(data);
                head = temp;
                head->next = head; // make it circular
                return;
            }
            do
            {
                temp = temp->next;
            } while (temp->next != head);
            p = new Node(data);
            p->next = head;
            head = p;
            temp->next = head;
            return;
        }
        else
        {
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            p = new Node(data);
            p->next = temp->next;
            temp->next = p;
        }
    }
};

int main()
{
    int arr[] = {4, 8, 1, 9, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    CircularLL list1;
    list1.create(arr, size);
    list1.display();
    list1.insert(4, 10);
    list1.display();
    list1.insert(7, 11);
    list1.display();
    list1.insert(0, 12);
    list1.display();

    // making list only from insert function
    CircularLL list2;
    list2.insert(0, 1);
    list2.display();
    list2.insert(1, 2);
    list2.display();
    list2.insert(0, 5);
    list2.display();
    return 0;
}