#include <iostream>
#include <queue>
using namespace std;

void inbuiltQueue()
{

    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);
    cout << q1.size() << endl;
    cout << q1.front() << endl;
    q1.pop();
    cout << q1.front() << endl;
    cout << q1.back() << endl;
}

int main()
{
    inbuiltQueue();

    return 0;
}