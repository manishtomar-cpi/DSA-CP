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
    Node *top = nullptr; // point to the top

public:
    void push(int val)
    {
        Node *temp = new Node(val);
        if (temp == nullptr)
        {
            cout << "cannot pushed: stack overflow!" << endl;
        }
        else
        {                     // we always add on the top in the LL because of constant time
            temp->next = top; // modified head
            top = temp;       // new added node is now head and the top element is now head->data
            cout << "pushed: " << val << endl;
        }
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "stack underflow: stack empty!" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next; // moving top to the next
            cout << "deleted " << temp->data << "!" << endl;
            delete temp; // deleting prev top
        }
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "stack empty!" << endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    int atIndex(int index)
    {
        Node *temp = top;
        for (int i = 0; temp != nullptr && i < index - 1; i++)
        { // here we are going to the position user entered checking temp as well if its null loop will break
            temp = temp->next;
        }
        if (temp != nullptr)
        { // means user passed valid position
            return temp->data;
        }
        else
        { // means invalid position entered because temp became null
            return -1;
        }
    }

    bool isFull()
    {
        Node *temp = new Node(-1);
        if (temp == nullptr)
        {
            // means heap is full
            delete temp;
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
        if (top == nullptr)
        { // if top not pointing on any node
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s1;
    s1.push(10);                                     //[10]
    cout << "Top element is: " << s1.peek() << endl; // 10
    s1.push(20);                                     //[20,10]
    s1.push(30);                                     //[30,20,10]
    s1.push(40);                                     //[40,30,20,10]
    cout << "Top element is: " << s1.peek() << endl; // 40
    s1.pop();                                        //[30,20,10]
    cout << "Top element is: " << s1.peek() << endl; // 30
    s1.pop();                                        //[20,10]
    s1.pop();                                        //[10]
    cout << "Top element is: " << s1.peek() << endl; // 10
    s1.pop();                                        //[]
    cout << "Top element is: " << s1.peek() << endl; //-1 invalid
    cout << boolalpha;
    cout << s1.isEmpty() << endl;  // true
    s1.push(10);                   //[10]
    cout << s1.isEmpty() << endl;  // false
    s1.push(20);                   //[20,10]
    s1.push(30);                   //[30,20,10]
    cout << s1.atIndex(2) << endl; // 20
    cout << s1.atIndex(4) << endl; //-1 invalid position filled
    cout << s1.atIndex(3) << endl; // 20
    cout << s1.isFull() << endl;

    return 0;
}