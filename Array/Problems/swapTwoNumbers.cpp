#include <iostream>
using namespace std;

void swapNums(int *a, int *b)
// if we passing the pointers then teh actual values are swap, otherwise the copy will create.
{
    int temp = 0;

    cout << "value pf a is without swap: " << *a << endl;
    cout << "value of b is without swap: " << *b << endl;

    // dereference the pointers
    temp = *a;
    *a = *b;
    *b = temp;

    cout << "value pf a is after swap: " << *a << endl;
    cout << "value of b is after swap: " << *b << endl;
}

void swapWithoutTemp(int *a, int *b)
{

    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "value pf a is without swap: " << *a << endl;
    cout << "value of b is without swap: " << *b << endl;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    cout << "value pf a is after swap: " << *a << endl;
    cout << "value of b is after swap: " << *b << endl;
}

void inBuiltSwap(int a, int b)
{
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "value pf a is without swap: " << a << endl;
    cout << "value of b is without swap: " << b << endl;
    swap(a, b);
    cout << "value pf a is after swap: " << a << endl;
    cout << "value of b is after swap: " << b << endl;
}

int main()
{
    int a = 3;
    int b = 6;

    swapNums(&a, &b);

    cout << "FROM MAIN value pf a is after swap: " << a << endl;
    cout << "FROM MAIN value of b is after swap: " << b << endl;

    int c = 8;
    int d = 9;

    swapWithoutTemp(&c, &d);

    cout << "FROM MAIN value pf c is after swap: " << c << endl;
    cout << "FROM MAIN value of d is after swap: " << d << endl;
    int e = 5;
    int f = 7;
    inBuiltSwap(e,f);
    return 0;
}