#include <iostream>
using namespace std;

int main()
{
    int a[10];

    a[0] = 2;
    a[4] = 9;

    cout << a[0] << endl; // 2
    cout << a[1] << endl; // garbage
    cout << a[2] << endl; // garbage
    cout << a[3] << endl; // garbage

    return 0;
}