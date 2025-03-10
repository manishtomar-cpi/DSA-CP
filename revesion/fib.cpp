#include <iostream>
#include <vector>
using namespace std;

int fib(int n)
{
    int first = 0;
    int second = 1;
    int sum = 0;

    if (n < 0)
    {
        return -1;
    }
    else if (n < 2 && n > 0)
    {
        return n;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            sum = first + second;
            first = second;
            second = sum;
        }
    }
    return sum;
}

int _FIB_REC_(int n, vector<int> &vec)
{

    if (n < 0)
    { // edge case
        return 0;
    }
    if (vec[n] != 0)
    {
        return vec[n]; // using memoization
    }
    else if (n == 0 || n == 1)
    { // base case
        return n;
    }
    int output = _FIB_REC_(n - 1, vec) + _FIB_REC_(n - 2, vec);
    vec[n] = output; //? why index[n] because if we assume we are at fib(2) then the calculated result will be for 2
    return output;
}

int main()
{
    int n = 12;
    // cout << fib(n) << endl;
    vector<int> vec(n, 0);
    cout << _FIB_REC_(50, vec) << endl;
    return 0;
}