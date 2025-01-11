#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {};
    Node() : next(nullptr) {};
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {};

    void enqueue(int val)
    {
        Node *temp = new Node(val);
        // full condition
        if (temp == nullptr)
        {
            cout << "queue full: cannot enqueue!" << endl;
        }
        else
        {
            if (front == nullptr)
            {                        // means our queue is empty
                front = rear = temp; // front and rear should be on same place
                cout << val << " enqueued!" << endl;
            }
            else
            {
                rear->next = temp;
                rear = temp;
                cout << val << " enqueued!" << endl;
            }
        }
    }

    void dequeue()
    {
        //empty condition
        if (front == nullptr)
        {
            cout << "queue empty: cannot dequeue!" << endl;
        }
        else
        {
            //if only one element in the queue
            if (front == rear)
            {
                front = rear = nullptr;
                cout << "dequeued : queue empty!" << endl;
            }
            else
            {
                //deleting head
                Node *temp = new Node(front->data);
                front = front->next;
                cout << "dequeued: " << temp->data << endl;
                delete temp;
            }
        }
    }

    bool isFull()
    {
        Node *temp = new Node(-1);
        if (temp == nullptr)
        {
            return true;
        }
        else
        {
            delete temp;
            return false;
        }
    }

    bool isEmpty()
    {
        return front == nullptr ? true : false;
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

    int getFront()
    {
        if (front == nullptr)
        {
            cout << "queue empty!" << endl;
            return -1;
        }
        else
        {
            return front->data;
        }
    }
    int getRear()
    {
        if (rear == nullptr)
        {
            cout << "queue empty!" << endl;
            return -1;
        }
        else
        {
            return rear->data;
        }
    }
};

int main()
{
    Queue q1;
    cout << boolalpha;
    cout << q1.isEmpty() << endl;  // true
    cout << q1.isFull() << endl;   // false
    q1.enqueue(10);                // 10
    q1.enqueue(20);                // 10, 20
    q1.enqueue(30);                // 10,20,30
    cout << q1.getFront() << endl; // 10
    cout << q1.getRear() << endl;  // 30
    cout << q1.size() << endl;     // 3
    q1.dequeue();                  // 20,30
    q1.dequeue();                  // 30
    q1.dequeue();                  // empty
    cout << q1.getFront() << endl; // -1
    cout << q1.getRear() << endl;  // -1
    q1.enqueue(100);
    cout << q1.getFront() << endl; // 100
    cout << q1.getRear() << endl;  // 100
    return 0;
}