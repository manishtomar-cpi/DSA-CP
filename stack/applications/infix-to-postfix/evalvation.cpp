#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val) : val(val), next(nullptr) {};
};

class Stack
{
private:
    Node *top;

public:
    Stack() : top(nullptr) {};

    void push(int val)
    {
        Node *temp = new Node(val);
        if (temp == nullptr)
        {
            cout << "stck overflow: cannot push!" << endl;
        }
        else
        {
            temp->next = top;
            top = temp;
            cout << "pushed: " << val << endl;
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
            Node *temp = new Node(top->val);
            top = top->next;
            cout << "poped: " << temp->val << endl;

            delete temp;
        }
    }

    int peek()
    {
        if (top == nullptr)
        {
            cout << "stack empty: nothing on top!" << endl;
            return -1;
        }
        else
        {
            return top->val;
        }
    }
    bool isEmpty()
    {
        return !top ? true : false;
    }
};

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int pre(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

string infixToPostfix(string str)
{
    Stack s1;
    int i = 0;
    string converted;

    while (i < str.length())
    {
        if (s1.isEmpty())
        { // stack empty
            if (isOperator(str[i]))
            {
                s1.push(str[i]);
            }
            else
            {
                converted += str[i];
            }
            i++;
        }
        else
        {
            if (isOperator(str[i]))
            {
                if (pre(s1.peek()) >= pre(str[i]))
                { // means if the top of the stack is heigher then the cuurent operand in pre then add the heigher into the converted and remove from stack
                    converted += s1.peek();
                    s1.pop();
                }
                else
                { // othervise add into stack
                    s1.push(str[i]);
                    i++;
                }
            }
            else
            {
                converted += str[i];
                i++;
            }
        }
    }
    while (!s1.isEmpty())
    { // if still some operators in the stack
        converted += s1.peek();
        s1.pop();
    }

    return converted;
}

int evalvation(string str)
{
    str = infixToPostfix(str);
    cout << str << endl;
    cout << "==================EVAL======================" << endl;
    Stack s2;
    int i = 0;
    int first;  // which poped second
    int second; // which poped first
    while (i < str.size())
    {
        if (s2.isEmpty())
        {
            int original = str[i] - '0'; // making integer

            s2.push(original);
            i++;
        }
        else
        {
            if (!isOperator(str[i]))
            {
                int original = str[i] - '0'; // making integer

                s2.push(original);
                i++;
            }
            else
            {
                first = s2.peek(); // top one is the second one
                s2.pop();
                second = s2.peek();
                s2.pop();
                if (str[i] == '+')
                {
                    s2.push(second + first);
                }
                else if (str[i] == '-')
                {
                    s2.push(second - first);
                }
                else if (str[i] == '*')
                {
                    s2.push(second * first);
                }
                else
                {
                    s2.push(second / first);
                }
                i++;
            }
        }
    }

    return s2.peek();
}

int main()
{

    string str = "1+4+5+2-3+6+8";

    // cout << infixToPostfix(str) << endl;
    cout << evalvation(str) << endl;
    return 0;
}