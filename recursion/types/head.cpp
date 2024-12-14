#include <iostream>
using namespace std;

//? head recursion is the recursion in which their is no task at the calling time

void func(int n)
{
    if (n > 0) // base case
    {
        //* if something here then it should not the example of head rec
        func(n - 1);
        cout << n << endl; // task 1
        // task 2
        // task 3
        //..
        //..
    }
}
//! we cant convert head rec into loop (as it is)