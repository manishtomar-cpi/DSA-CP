#include <iostream>
using namespace std;

//! fib using for loop
void fib(int n)
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

    cout << sum << endl;
}

//! using rec
int fib_rec(int n)
{
    // static int first = 0;
    // static int second = 1;
    // int sum = first + second;
    // if (n > 2)
    // {
    //     first = second;
    //     second=sum;
    //     return fib_rec(n - 1);
    //     // sum = first+second;
    // }
    // return sum;

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
    return fib_rec(n - 1) + fib_rec(n - 2);
}

int main()
{
    // fib(7);

    cout << fib_rec(4) << endl;
    return 0;
}