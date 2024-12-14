#include <iostream>
using namespace std;

//? tail recursion is the recursion in which their is no task at the returning time

void func(int n)
{
    if (n > 0) // base case
    {
        cout << n << endl; // task 1
        // task 2
        // task 3
        //..
        //..
        func(n - 1);
        // cout << n << endl //! this is not the tail because it have the task to perform at return type;
    }
}
//! if we compare the tail with loop so the time comp remains same O(N) in both case but time comp is diff because recursive func will create the activation records in the stack and take O(N) on the other hand loop only will take O(1)