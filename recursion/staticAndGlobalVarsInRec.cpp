#include <iostream>
using namespace std;

int a = 0;
int checkWithLocal(int n)
{
    int x = 0;

    if (n > 0)
    {
        x++;
        return checkWithLocal(n - 1) + x;
    }
    return 0; // when equal to 0
}

int checkWithGlobal(int n)
{
    if (n > 0)
    {
        a++;
        return checkWithGlobal(n - 1) + a;
    }
    return 0;
}

int checkWithStatic(int n)
{
    static int a = 0;
    if (n > 0)
    {
        a++;
        return checkWithStatic(n - 1) + a;
    }
    return 0;
}

int main()
{
    // cout << checkWithLocal(4) << endl; // 4 not 12 //!because when recursive call happens each time 'x' became 0 then x++, so value of x in each time is 1 then 0+1 -> 1+1 -> 2+1 -> 3+1 = 4
    // cout << checkWithGlobal(4) << endl; // 16 not 10 //! because a is declared globally so in the last execution of recursive call a becomes 4 then first recall -> 0+4. second recall -> 4+4. third recall -> 8+4. fourth recall -> 12+4 = 16
    cout << checkWithStatic(4) << endl; //16 //! same as local because static var only declare once no more copy is generated during execution 
    return 0;
}