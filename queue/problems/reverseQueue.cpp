#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &q1)
{
    stack<int> s1;
    while (!q1.empty())
    {
        s1.push(q1.front());
        q1.pop();
    }
    while (!s1.empty())
    {
        q1.push(s1.top());
        s1.pop();
    }
}

int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    cout << "=====BEFORE=====" << endl;
    cout << q1.front() << endl;
    reverseQueue(q1);
    cout << "=====AFTER=====" << endl;
    cout << q1.front() << endl;

    return 0;
}