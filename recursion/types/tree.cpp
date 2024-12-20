#include <iostream>
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);              // 1. Recursive call (left branch)
        cout << n << " ";       // 2. Print current value
        fun(n - 1);              // 3. Recursive call (right branch)
    }
}

int main()
{
    fun(3); //1213121 is the output
    return 0;
}