#include <iostream>
using namespace std;

void func(int n)
{
    if (n > 0)//base case 
    {
        cout << n << " ";
        func(n - 1); //function calling itself
    }
}

int main()
{
    int a = 3;
    func(a);

    return 0;
}