#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int priority; // for priority of the adding data, highest number -> highest priority
    Node *next;
    Node *prev;

    Node(int val, int pri) : data(val), priority(pri), next(nullptr), prev(nullptr) {};
};

class PriorityQueue
{
private:
    Node *front;

public:
    PriorityQueue() : front(nullptr) {};

    void displayQueue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            Node *temp = front;
            cout << "Priority Queue: [ ";
            while (temp != nullptr)
            {
                cout << "(" << temp->data << ", P" << temp->priority << ")";
                temp = temp->next;
                if (temp != nullptr)
                    cout << " -> ";
            }
            cout << " ]" << endl;
        }
    }

    void enqueue(int data, int priority)
    {
        Node *temp = new Node(data, priority);
        // check full
        if (temp == nullptr)
        {
            cout << "queue full!" << endl;
        }
        else
        {
            if (front == nullptr)
            { // means empty
                front = temp;
                cout << data << " enqueued!" << endl;
                displayQueue();
            }
            else
            { // now we are adding according to priority

                // check for head priority
                if (front->priority < priority)
                { // now we need to update the head
                    temp->next = front;
                    front->prev = temp;
                    front = temp;
                    cout << data << " enqueued!" << endl;
                    displayQueue();
                }
                else
                {
                    Node *temp1 = front;
                    while (temp1->next && temp1->next->priority >= priority) //why take temp1->next-<pri because we need to check the next one always
                    { // loop till we get the lowest priority node or we reach at end
                        temp1 = temp1->next;
                    }
                    temp->next = temp1->next;
                    temp1->next = temp;
                    temp->prev = temp1;
                    cout << data << " enqueued!" << endl;
                    displayQueue();
                }
            }
        }
    }

    void dequeue()
    {
        int x;
        // check full
        if (front == nullptr)
        {
            cout << "queue empty!" << endl;
        }
        else
        {
            x = front->data;
            front = front->next;
            cout << "dequeued: " << x << endl;
            displayQueue();
        }
    }
    int higherPriority()
    {
        return (!front) ? -1 : front->data;
    }

    int lowestPriority()
    {
        if (front == nullptr)
        {
            return -1;
        }
        else
        {
            Node *temp = front;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            return temp->data;
        }
    }
    ~PriorityQueue()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main()
{
    PriorityQueue p1;

    p1.enqueue(7, 9);                    // 7
    p1.enqueue(8, 6);                    // 7,8
    p1.enqueue(6, 6);                    // 7,8,6
    p1.enqueue(11, 7);                   // 7,11,8,6
    p1.dequeue();                        // 11,8,6
    cout << p1.higherPriority() << endl; // 11
    cout << p1.lowestPriority() << endl; // 6

    return 0;
}