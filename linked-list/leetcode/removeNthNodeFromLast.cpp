#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {} // Constructor for Node
};

class LinkedList
{
private:
    Node *head; // Pointer to the first node

public:
    LinkedList() : head(nullptr) {} // Constructor to initialize an empty list

    ~LinkedList() // Destructor to clean up memory
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp; // Free the memory of each node
        }
        head = nullptr;
    }

    // Function to create a linked list from an array
    void create(int arr[], int size)
    {
        if (size == 0)
            return;

        head = new Node(arr[0]);
        Node *last = head;

        for (int i = 1; i < size; i++)
        {
            Node *temp = new Node(arr[i]);
            last->next = temp;
            last = temp;
        }
    }

    // Function to display the linked list
    void display()
    {
        Node *current = head;
        cout << "[ ";
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null ]" << endl;
    }

    Node *reverse()
    {
        Node *first = head;
        Node *second = nullptr;
        Node *third = nullptr;

        while (first != nullptr)
        {
            third = second;
            second = first;
            first = first->next;
            second->next = third;
        }
        head = second;
        return second;
    }

    void remove(int n)
    {
        Node *first = head;
        Node *second = nullptr;
        Node *third = nullptr;

        head = reverse();
        first = nullptr;
        third = head;
        if (n == 1)
        {
            first = head;
            head = first->next;
            delete first;

            head = reverse();

            display();

            return;
        }
        for (int i = 0; i < n - 2; i++)
        {
            third = third->next;
        }
        first = third->next;
        third->next = first->next;
        delete first;

        head = reverse();
        display();
    }
};

int main()
{
    int arr[] = {1, 2, 3};
    int size = 3;

    LinkedList list;
    list.create(arr, size);
    list.display();
    list.remove(3);
    return 0;
}