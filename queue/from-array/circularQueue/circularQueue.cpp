#include <iostream>
using namespace std;

class Queue
{
private:
    int capacity;
    int front;
    int rear;
    int *helper_array;

public:
    Queue(int size) : capacity(size), front(0), rear(0) // making circular queue in which front and rear is init with zero becaue the one place is always emoty to make it circular
    {
        helper_array = new int[capacity];
    }

    void enqueue(int val)
    {
        if ((rear + 1) % capacity == front)
        { // so this logic is '%' gives us reminder means the capacity is 6, and rear is at 6 front is on 0 so (6+1)/7 is = and front is 0 so queue is full
            cout << "queue full: cannot enqueue" << endl;
        }
        else
        {
            // assume we are inserting the first element -> rear is 0 1%7 reminder is 1 so on array[1] we are filling new value
            rear = (rear + 1) % capacity;
            helper_array[rear] = val;
        }
    }
    void dequeue()
    {
        if (front == rear)
        { // means queue empty
            cout << "cannot deque: queue empty!" << endl;
        }
        else
        {
            front = (front + 1) % capacity;
        }
    }

    int getFront()
    {
        if (front == rear)
        {
            cout << "queue empty!" << endl;
            return -1;
        }
        else
        {
            return helper_array[(front + 1) % capacity];
        }
    }

    int getRear()
    {
        if (front == rear)
        {
            cout << "queue empty!" << endl;
            return -1;
        }
        else
        {
            return helper_array[rear];
        }
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return (rear + 1) % capacity == front ? true : false; // means the same condition as we took at time of inserting
    }
};

int main()
{
    Queue q1(4);
    cout << boolalpha;
    cout << q1.isEmpty() << endl;  // T
    cout << q1.isFull() << endl;   // F
    q1.enqueue(10);                // 10
    q1.enqueue(20);                // 20
    q1.enqueue(30);                // 30
    q1.enqueue(40);                //! not enqued because we only can store capacity -1 element
    q1.dequeue();                  // 20, 30
    cout << q1.getFront() << endl; // 20
    cout << q1.getRear() << endl;  //30

    return 0;
}