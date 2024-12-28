#include <iostream>
#include <vector>
using namespace std;

//! fib using for loop
int fib(int n)
{

    int first = 0;
    int second = 1;
    int sum = 0;
    // cout << first << " " << second << " ";

    for (int i = 0; i < n - 1; i++)
    {
        sum = first + second;
        // cout << sum << " ";
        first = second;
        second = sum;
    }

    return sum;
}

//! using rec -> this is called excessive rec because it is calling the rec calls many times like f(3) , f(2), f(1), f(0)
int fib_rec(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (n < 0)
    {
        return -1;
    }
    return fib_rec(n - 1) + fib_rec(n - 2); //! time O(2 pow n);
}

//! O(N) using memoization
vector<int> f(10, -1);
int mFib(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 1] == -1)
        {
            f[n - 1] = mFib(n - 1);
        }
        if (f[n - 2] == -1)
        {
            f[n - 2] = mFib(n - 2);
        }
        return f[n - 2] + f[n - 1];
    }
}
int main()
{
    cout << fib(40) << endl;

    cout << "rec" << endl;
    // cout << fib_rec(50) << endl;
    // cout << mFib(5) << endl;
    return 0;
}