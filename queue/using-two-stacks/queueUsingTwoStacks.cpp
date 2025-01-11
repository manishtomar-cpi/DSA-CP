#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {};
};

class Stack
{

private:
    Node *top;

public:
    Stack() : top(nullptr) {};
    void push(int data)
    {
        Node *temp = new Node(data);
        // full condition
        if (temp == nullptr)
        {
            cout << "stack full!" << endl;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "stack empty!" << endl;
        }
        else
        {
            Node *temp = new Node(top->data);
            top = top->next;
            cout << "pop " << temp->data << "!" << endl;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return (!top) ? true : false;
    }

    bool isFull()
    {
        Node *temp = new Node(-1);
        return (!temp) ? true : false;
    }

    int peek()
    {
        return (!top) ? -1 : top->data;
    }

    friend class Queue;
};

class Queue
{
private:
    Stack s1; // for enqueue
    Stack s2; // for dequeue

public:
    void enqueue(int data)
    {
        if (s1.isFull())
        {
            cout << "cannot enqueue: queue full!" << endl;
        }
        else
        {
            s1.push(data);
            cout << "enqueued: " << data << "!" << endl;
        }
    }

    void dequeue()
    {
        if (s1.isEmpty() && s2.isEmpty())
        {
            cout << "Queue Empty: cannot dequeue!" << endl;
        }
        else
        {
            if (s2.isEmpty())
            {
                while (!s1.isEmpty())
                {
                    s2.push(s1.peek());
                    s1.pop();
                }
                cout << "dequeued: " << s2.peek() << "!" << endl;
                s2.pop();
            }
            else
            {
                cout << "dequeued: " << s2.peek() << "!" << endl;
                s2.pop();
            }
        }
    }

    int getRear()
    {
        if (s1.isEmpty() && s2.isEmpty())
        { // both stack empty
            return -1;
        }
        else
        {
            if (!s1.isEmpty())
            {
                return s1.peek();
            }
            else
            {
                // push s2 into s1 then  return peek of s1
                while (!s2.isEmpty())
                {
                    s1.push(s2.peek());
                    s2.pop();
                }
                return s1.peek();
            }
        }
    }

    int getFront()
    {
        if (s1.isEmpty() && s2.isEmpty())
        {
            return -1; // means queue empty
        }
        else
        {
            if (!s2.isEmpty())
            {
                // means s2 is not empty then the topmost element in the s2 is the front one
                return s2.peek();
            }
            else
            {
                while (!s1.isEmpty())
                {
                    s2.push(s1.peek());
                    s1.pop();
                }

                return s2.peek();
            }
        }
    }
};

int main()
{
    Queue q1;

    q1.dequeue();                  // empty
    q1.enqueue(10);                // 10
    q1.enqueue(20);                // 10,20
    q1.enqueue(30);                // 10,20,30
    q1.dequeue();                  // 20,30
    q1.enqueue(40);                // 20,30,40
    q1.dequeue();                  // 30,40
    cout << q1.getFront() << endl; // 30
    cout << q1.getRear() << endl;  // 40

    return 0;
}