#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {} // this is the Parameterized constructor with init list which helps us to make the node without using Node *name = new Node , and give the data and all
};

class circularLL
{
private:
    Node *head;

public:
    circularLL() : head(nullptr) {}; // this is the default constructor which helps us not to define or inti the head in the main now when we create the object of this class the head is automatically generated

    void create(int arr[], int size)
    {
       head = new Node (arr[0]); // created first node , head is now pointing to this node
        // we dont need to write head ->next null it was set in the constructor in the node class
        Node *last = head;
        for (int i = 1; i < size; i++)
        {
            Node *temp = new Node(arr[i]);
            last->next = temp;
            last = temp;
        }
        last->next = head; // to make it circular the last node is pointing to head
    }

    void display()
    {
        if (head == nullptr)
            return; // means list is empty

        Node *current = head;
        cout << "[ ";
        do
        { // this statement run once without checking the while condition, we use do while because in while we cant write (current !=head) because in the very fist time current is equal to head
            cout << current->data << " - > ";
            current = current->next; // now it is next
        } while (current != head); // now while is checking
        cout << "(head) ]" << endl;
    }
};

int main (){
    int arr[] = {1,2,36,8,5};
    int size = 5;

    circularLL list1;//now first list is created with the head to null by default constructor
    list1.create(arr,size);
    list1.display(); //no need to pass head 

    return 0;
}