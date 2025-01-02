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
        last->next = head; //now make the last pointing to first
        head->prev = last; //first prev to last
    }

    void display()
    {
        cout << "======BY HEAD======" << endl;

        Node *temp = head;

        cout << "[ ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head) ]" << endl;
    }

    void displayByTail()
    {
        cout << "======BY TAIL======" << endl;

        Node *temp = tail;

        cout << "[ ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail);
        cout << "(tail) ]" << endl;
    }
};

int main()
{
    int arr[] = {2, 5, 6, 7, 3, 9, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    DoublyLL list1;
    list1.create(arr, size);
    list1.display();
    list1.displayByTail();
    return 0;
}