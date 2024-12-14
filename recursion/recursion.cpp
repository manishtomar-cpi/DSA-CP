#include <iostream>
using namespace std;

//! diff b/w loop and recursion is the loop dont have the returning phase but the recursion have but recursive func are memory consuming -> see the image 
void func1(int n)
{
    if (n > 0) // base case
    {
        //! calling phase the print statement will be executed in the calling phase -> 3,2,1 will be the output
        cout << n << " ";
        func1(n - 1); // function calling itself
        //! no returning task
    }
}

void func2(int n)
{
    if (n > 0)
    {
        func2(n - 1); // recursive call //! first the recursive calls will be executed then the print statement
        //?returning task
        cout << n << endl; //! out put is 1 2 3 -> after recursive the bottom-up/returning phase will be executed in that phase we will execute the print statement
    }
}

void understandingCallingAndReturningPhase(int n)

{
    if (n > 0)
    {
        cout << "calling phase ";
        understandingCallingAndReturningPhase(n - 1);
        if (n == 1)
        {
            cout << endl;
        }
        cout << "returning phase ";
    }
    // calling phase calling phase calling phase
    // returning phase returning phase returning phase
}
int main()
{
    int a = 3;
    // func1(a);
    understandingCallingAndReturningPhase(3);

    return 0;
}