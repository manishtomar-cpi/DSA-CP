#include <iostream>
using namespace std;

int power(int num, int pow)
{
    if (pow < 0)
    {
        return -1;
    }

    if (pow == 0)
    {
        return 1;
    }
    //!we can do below one as well
    //  if (pow == 0)
    // {
    //     return 1;
    // }

    return (power(num, pow - 1) * num);
}

int main()
{
    cout << power(2, 6) << endl;

    return 0;
}