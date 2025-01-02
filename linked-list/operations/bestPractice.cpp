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
        if (size == 0) return;

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
};

int main()
{
    int arr[] = {1, 4, 3, 7, 5, 9, 10};
    int size = 7;

    LinkedList list;
    list.create(arr, size);
    list.display();

    return 0;
}
