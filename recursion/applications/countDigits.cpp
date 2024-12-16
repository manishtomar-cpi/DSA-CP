#include <iostream>
using namespace std;

int digitCount(int n)
{
    // static int count = 0;
    // if (n == 0)
    // {
    //     return count;
    // }
    // if (n >= 1)
    // {
    //     count++;
    //     return digitCount(n/10);
    // }

    if (n == 0)
    {
        return 0;
    }
    return digitCount(n / 10) + 1;
}
int main()
{
    int num = 100;

    cout << digitCount(num) << endl;
    return 0;
}