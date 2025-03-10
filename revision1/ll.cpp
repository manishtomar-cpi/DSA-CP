#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() : next(nullptr) {};
    Node(int data) : data(data), next(nullptr) {};
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {};

    int insert(int val)
    {
        // first check empty LL
        if (head == nullptr)
        {
            head = new Node(val);
            tail = head; // tail is also the head when the list is empty
            cout << val << " inserted on head!" << endl;
        }
        else
        {
            // now we have tail, take advantage of that, means we don't have to go at the end each time on inserting we can insert in O(1)
            Node *temp = new Node(val);
            // now tail is at the last node , so last -> next = new node
            tail->next = temp;

            // and tail is again on last
            tail = temp;
            cout << val << " inserted!" << endl;
        }

        return val;
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "empty list" << endl;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << nullptr << endl;
        }
    }
};

int main()
{
    LinkedList l1;
    l1.insert(10);
    l1.insert(20);
    l1.print();
    return 0;
}
