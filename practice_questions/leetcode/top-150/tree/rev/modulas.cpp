#include <iostream>
using namespace std;

int main()
{
    int i = 0;
    int currNum = 4;
    int secondNum = 9;
    int sum = 0;
    sum = ((sum % 10) * 10) + currNum;
    cout << "first sum: " << sum << endl;
    sum = ((sum % 10) * 10) + secondNum;
    cout << sum << endl;
    sum = sum / 10;
    cout << "AFTER  remoiving last" << endl;
    cout << sum << endl;

    return 0;
}
