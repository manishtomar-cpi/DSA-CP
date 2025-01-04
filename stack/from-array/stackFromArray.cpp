#include <iostream>
using namespace std;

class Stack
{
private:
    //! ENCAPSULATION these all the privates we cant access those because these are the backbone of the stack we cant modify any one of these from the main
    int *arr;     // pointer to the array -> we are taking the array dynamically
    int capacity; // how much capacity of the stack is
    int top;      // pointing to the top element

public:
    Stack(int size) : capacity(size), top(-1)
    {
        arr = new int[capacity]; // make array dynamically by the help of constructor
    }

    ~Stack() // run at the end to free all the memory
    {
        delete[] arr;
        cout << "stack memory released" << endl;
    }

    void push(int val)
    {
        if (top >= capacity - 1) // means here we are checking the overflow means we can't store the values above the capacity
        {
            cout << "stack overflow: cannot push " << val << endl;
        }
        else
        {
            arr[++top] = val; // pre increment the top -> comes 0 on first and arr[0] store the value
            cout << "pushed: " << val << endl;
        }
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "stack underflow: no element on the top" << endl;
        }
        else
        {
            cout << "popped " << arr[top--] << " from the stack." << endl; // means post decrement the top first it will give value of arr[top] then decrement
        }
    }

    int peek()
    {

        if (top < 0)
        {
            cout << "stack empty!" << endl;
        }
        else
        {
            return arr[top];
        }
    }

    int onIndex(int index)
    {
        if (index < 0 || index >= capacity)
        {
            cout << "invalid index!" << endl;
        }
        if (top < 0)
        {
            cout << "stack empty!" << endl;
        }
        if (index < 0 || index > top)
        {
            cout << "index empty!" << endl;
            return -1;
        }
        else
        {
            return arr[index];
        }
    }

    bool isEmpty()
    {
        return top < 0; // means if top < 0
    }
    bool isFull()
    {
        return top >= capacity - 1; // means if capacity is 5 the valid index of an array is 4 thats why its -4;
    }
};

int main()
{
    Stack s1(5); // stack of size 5
    s1.push(10); //[10,_,_,_,_]
    cout << "the top is: " << s1.peek() << endl;
    s1.push(20);                                 //[10,20,_,_,_]
    s1.push(30);                                 //[10,20,30,_,_]
    s1.push(40);                                 //[10,20,30,40,_]
    cout << "the top is: " << s1.peek() << endl; // 40
    s1.push(50);                                 //[10,20,30,40,50]
    cout << "the top is: " << s1.peek() << endl; // 50
    s1.push(60);                                 // not allowed -> overflow
    s1.pop();                                    //[10,20,30,40,_]
    cout << "the top is: " << s1.peek() << endl; // 40
    s1.pop();                                    //[10,20,30,_,_]
    cout << "the top is: " << s1.peek() << endl; // 30

    cout << "value on the index: " << s1.onIndex(1) << endl; // 20
    cout << "value on the index: " << s1.onIndex(3) << endl; //-1 because on 0 -> 10, on 1 -> 20, on 2 ->30, on 3,4, and 5 is _

    return 0;
}