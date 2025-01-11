#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    // because we are using doubly linkedlist
    // why?
    // because in singly ll deletion from rear will take O(n) time but on doubly will take O(1) time
    Node *next;
    Node *prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {};
    Node() : next(nullptr), prev(nullptr) {};
};

class Deque
{
private:
    Node *front;
    Node *rear;

public:
    Deque() : front(nullptr), rear(nullptr) {};

    void enqueueAtFront(int val)
    {
        // STEP 1- check full
        Node *temp = new Node(val);
        if (temp == nullptr)
        {
            cout << "queue full!" << endl;
        }
        else
        {
            // check if empty
            if (front == nullptr)
            {
                front = rear = temp;
                cout << val << " enqueued at front!" << endl;
            }
            else
            {
                temp->next = front;
                front->prev = temp;
                front = temp;
                cout << val << " enqueued at front!" << endl;
            }
        }
    }

    void dequeueAtFront()
    {
        // check empty
        if (front == nullptr)
        {
            cout << "queue empty!" << endl;
        }
        else
        {
            front = front->next;
            // check if there was only element
            if (!front)
            { // means front became null
                rear = nullptr;
                cout << "dequeued at front: queue empty now!" << endl;
            }
            else
            {
                front->prev = nullptr;
                cout << "dequeued at front!" << endl;
            }
        }
    }

    void enqueueAtRear(int val)
    {
        // check full
        Node *temp = new Node(val);
        if (temp == nullptr)
        {
            cout << "queue full!" << endl;
        }
        else
        {
            // check empty
            if (front == nullptr)
            {
                front = rear = temp;
                cout << val << " enqueued at top!" << endl;
            }
            else
            {
                rear->next = temp;
                temp->prev = rear;
                rear = temp;
                cout << val << " enqueued!" << endl;
            }
        }
    }

    void dequeueAtRear()
    {
        // check empty
        if (front == nullptr)
        {
            cout << "queue empty!" << endl;
        }
        else
        {
            Node *temp = rear;
            rear = temp->prev; // rear pointing on the second last node.
            if (!rear)
            {
                // means only one element was in the queue
                front = rear = nullptr;
                cout << "queue became empty!" << endl;
            }
            else
            {
                rear->next = nullptr;
                cout << "dequeued from rear!" << endl;
            }
        }
    }

    int getFront()
    {
        // check empty
        return (!front) ? -1 : front->data;
    }

    int getRear()
    {
        return (!rear) ? -1 : rear->data;
    }

    bool isEmpty()
    {
        return (front == nullptr && rear == nullptr) ? true : false;
    }

    int size()
    {
        Node *temp = front;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main()
{
    Deque q1;
    cout << boolalpha;
    cout << q1.isEmpty() << endl;  // T
    q1.enqueueAtFront(10);         // 10
    q1.enqueueAtRear(20);          // 10, 20
    cout << q1.getFront() << endl; // 10
    cout << q1.getRear() << endl;  // 20
    q1.enqueueAtFront(30);         // 30,10,20
    cout << q1.getFront() << endl; // 30
    cout << q1.getRear() << endl;  // 20
    q1.enqueueAtRear(40);          // 30,10,20,40
    cout << q1.getFront() << endl; // 30
    cout << q1.getRear() << endl;  // 40
    q1.dequeueAtFront();           // 10,20,40
    cout << q1.getFront() << endl; // 10
    cout << q1.getRear() << endl;  // 40
    q1.dequeueAtRear();            // 10,20
    cout << q1.getFront() << endl; // 10
    cout << q1.getRear() << endl;  // 20
    cout << q1.size() << endl;     // 2

    q1.dequeueAtRear();            // 10
    q1.dequeueAtRear();            // empty
    cout << q1.size() << endl;     // 0
    cout << q1.getFront() << endl; //-1
    cout << q1.getRear() << endl;  //-1

    return 0;
}