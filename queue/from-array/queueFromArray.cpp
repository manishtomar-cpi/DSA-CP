#include <iostream>
using namespace std;

class Queue
{
private:
    int capacity;     // The capacity of the queue
    int front;        // Front of the queue
    int rear;         // Rear of the queue
    int *queue_array; // Dynamically allocated array for the queue

public:
    // Constructor to initialize the queue with the given capacity
    Queue(int val) : capacity(val), front(-1), rear(-1)
    {
        queue_array = new int[capacity]; // Dynamically allocating memory for the queue
    }

    // Destructor to free the dynamically allocated memory
    ~Queue()
    {
        delete[] queue_array;
    }

    void enqueue(int val) // adding at back
    {
        // inserting = enqueue
        if (rear == capacity - 1)
        {
            cout << "queue full: cannot enqueue!" << endl;
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                // means queue empty
                queue_array[++rear] = val;
                front++;
                cout << "enqued at front: " << val << endl;
            }
            else
            {
                queue_array[++rear] = val;
                cout << "enqued: " << val << endl;
            }
        }
    }

    void dequeue() // removing from front
    {
        if (front == -1 || front > rear)
        { // means empty
            cout << "queue empty: cannot deque!" << endl;
        }
        else
        {
            front++;
            if (front > rear)
            { // Reset queue if last element is dequeued
                front = -1;
                rear = -1;
            }
        }
    }

    int getFront()
    {
        if (front == -1)
        { // means empty
            cout << "queue empty!" << endl;
            return -1;
        }
        else
        {
            return queue_array[front];
        }
    }

    int getRear()
    {
        if (rear == -1)
        { // means empty
            cout << "queue empty!" << endl;
            return -1;
        }
        else
        {
            return queue_array[rear];
        }
    }

    bool isFull()
    {
        return rear == capacity - 1 ? true : false;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1) || front > rear;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "<- Front | ";
            for (int i = 0; i < capacity; i++)
            {
                if (i < front || i > rear)
                {
                    cout << "   "; // Empty spaces in queue
                }
                else if (i == front && i == rear)
                {
                    cout << " * " << queue_array[i] << " * "; // Only one element in queue
                }
                else if (i == front)
                {
                    cout << " * " << queue_array[i]; // Front of the queue
                }
                else if (i == rear)
                {
                    cout << queue_array[i] << " * "; // Rear of the queue
                }
                else
                {
                    cout << queue_array[i]; // Regular queue element
                }
                if (i < capacity - 1)
                    cout << " | ";
            }
            cout << " | Rear ->" << endl;
        }
    }
};

int main()
{
    Queue q1(5);
    cout << boolalpha;

    cout << q1.isFull() << endl;   // false
    cout << q1.isEmpty() << endl;  // true
    q1.enqueue(10);                // 10
    cout << q1.getFront() << endl; // 10
    cout << q1.getRear() << endl;  // 10
    q1.dequeue();                  // empty queue
    cout << q1.getFront() << endl; //-1
    cout << q1.getRear() << endl;  //-1
    q1.enqueue(10);                // 10
    q1.enqueue(20);                // 10,20
    q1.enqueue(30);                // 10,20,30
    q1.enqueue(40);                // 10,20,30,40
    q1.enqueue(50);                // 10,20,30,40,50
    cout << q1.getFront() << endl; // 10
    cout << q1.getRear() << endl;  // 50
    q1.dequeue();                  // 20,30,40,50
    cout << q1.getFront() << endl; // 20

    q1.enqueue(10);                //! not enqued because the rear is still on capacity -1 this is the drawback using array for making queue
    cout << q1.getFront() << endl; // 20
    cout << q1.getRear() << endl;  // 50
    q1.display();                  // 20,30,40,50

    return 0;
}
