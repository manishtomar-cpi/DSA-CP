#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void defaultPQ()
{ // MAX pq by default
    priority_queue<int> pq;

    pq.push(10);
    pq.push(19);
    pq.push(1);
    pq.push(45);
    pq.push(46);
    pq.push(16);
    pq.push(17);

    //?geting size
    cout << pq.size() << endl; // 7

    //?geting top
    cout << pq.top() << endl; // 46 -> because its max by default so the max element is on the top

    // traversing
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    // 46 45 19 17 16 10 1
}

void _MIN_PQ()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(19);
    pq.push(1);
    pq.push(45);
    pq.push(46);
    pq.push(16);
    pq.push(17);

    //?geting size
    cout << pq.size() << endl; // 7

    //?geting top
    cout << pq.top() << endl; // 1 

    // traversing
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    // 1 10 16 17 19 45 46
}

int main()
{
    defaultPQ();
    _MIN_PQ();
    return 0;
}