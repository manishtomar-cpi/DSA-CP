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

    void deleteNode(int pos)
    {
        if (pos < 0)
        {
            return;
        }
        Node *temp = head;
        Node *p = nullptr;
        if (pos == 0)
        {
            do
            {
                temp = temp->next;
            } while (temp->next != head);
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
        else
        {
            for (int i = 0; i < pos - 1; i++)
            {
                p = temp;
                temp = temp->next;
            }
            p->next = temp->next;
            delete temp;
        }
    }

    void display()
    {
        Node *temp = head;
        cout << "[ ";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)]" << endl;
    }
};

int main()
{
    int arr[] = {4, 8, 1, 4, 6, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    CircularLL list1;
    list1.create(arr, size);
    list1.display();
    list1.deleteNode(0);
    list1.display();
    list1.deleteNode(3);
    list1.display();
    list1.deleteNode(4);
    list1.display();
    return 0;
}