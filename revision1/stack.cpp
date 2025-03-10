#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : next(nullptr) {};
    Node(int val) : data(val), next(nullptr) {};
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {};

    int push(int val)
    {
        Node *temp = new Node(val);
        if (temp == nullptr)
        {
            cout << "cannot push: stack overflow!" << endl;
        }
        else
        {
            temp->next = top;
            top = temp;
            cout << val << " inserted!" << endl;
        }
        return val;
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "cannot pop: stack empty!" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            cout << temp->data << " poped!" << endl;
            delete temp;
        }
    }
    int peek()
    {
        return top == nullptr ? -1 : top->data;
    }

    bool isEmpty() { return top == nullptr ? true : false; }
};

int main()
{
    Stack s1;
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    cout << s1.peek() << endl;
    s1.pop();
    cout << s1.peek() << endl;
    cout << boolalpha;
    cout << s1.isEmpty()<< endl;
    return 0;
}