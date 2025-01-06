#include <iostream>
#include <string>
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
        if (temp == nullptr)
        {
            cout << "stack overflow: cannot push!" << endl;
        }
        else
        {
            temp->next = top;
            top = temp;
            cout << "pushed: " << data << endl;
        }
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "stack underflow: cannot pop!" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            cout << "pop: " << temp->data << endl;
            delete temp;
        }
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "stack empty!" << endl;
        }
        else

            return top->data;
        return -1;
    }
};

bool paraMatching(string s)
{
    Stack s1;
    if (s.size() == 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                s1.push(s[i]);
            }
            else
            {

                if (s[i] == ')')
                {
                    if (s1.peek() != '(')
                    {
                        return false;
                    }
                }

                if (s[i] == ']')
                {
                    if (s1.peek() != '[')
                    {
                        return false;
                    }
                }

                if (s[i] == '}')
                {
                    if (s1.peek() != '{')
                    {
                        return false;
                    }
                }
                s1.pop();
            }
        }
    }
    return s1.peek() == -1 ? true : false;
}

int main()
{
    cout << boolalpha;
    cout << paraMatching("(([))");
    return 0;
}