#include <iostream>
using namespace std;

int countZeros(int n)
{
    // code here
    int count = 0;
    if (n == 0)
    {
        return 0;
    }
    if (n % 10 == 0)
    {
        count++;
    }

    return (countZeros(n / 10)) + count;
}

int main()
{
    int num = 199;
    cout << countZeros(num) << endl;

    return 0;
}