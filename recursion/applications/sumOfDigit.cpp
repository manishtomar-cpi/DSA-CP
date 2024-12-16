#include <iostream>
using namespace std;

int sumOfDigit(int n)
{
    if (n  == 0)
    {
        return 0;
    }
    int mod = n % 10; // giving reminder //! but n/10 gives in case of 1234 it will give 123
    return sumOfDigit(n / 10) + mod;
}

int main()
{
    int dig = 1234;
    cout << sumOfDigit(dig) << endl;

    return 0;
}
