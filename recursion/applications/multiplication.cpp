#include <iostream>
using namespace std;

int mult(int number, int multiplicationTo)
{
     if (multiplicationTo == 0)
    {
        return 0;
    }
    if (multiplicationTo > 0)
    {
        return mult(number, multiplicationTo - 1) + number;
    }
}

int main()
{
    int number = 2;
    int multTo = 12;

    cout << mult(number, multTo);

    return 0;
}