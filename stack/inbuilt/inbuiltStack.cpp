#include <iostream>
#include <stack>
#include <algorithm>>
using namespace std;

void inbuiltStack()
{
    stack<int> s;
    stack<int> s1;
    s1.push(9);

    s.push(1); // for pushing
    s.push(2);
    s.push(3);

    s.pop();                 // poping
    cout << s.top() << endl; // top element 2
    cout << boolalpha;
    cout << s.empty() << endl;
    s.push(4);

    cout << s.size() << endl; // 2

    // swap content of 2 stacks
    s.swap(s1);
    cout << s.top() << endl;   // 9
    cout << s.size() << endl;  // 1
    cout << s1.size() << endl; // 3
    cout << s.top() << endl; // 9
}

int main()
{
    inbuiltStack();

    return 0;
}