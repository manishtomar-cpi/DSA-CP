#include <iostream>
using namespace std;

void func1(int n)
{
    if (n > 0)//base case 
    {
        //!calling phase the print statement will be executed in the calling phase -> 3,2,1 will be the output 
        cout << n << " ";
        func1(n - 1); //function calling itself
        //!no returning task
    }
}

void func2 (int n ){
    if(n>0){
        func2(n-1);//recursive call //! first the recursive calls will be executed then the print statement 
        //?returning task
        cout << n << endl; //! out put is 1 2 3 -> after recursive the bottom-up/returning phase will be executed in that phase we will execute the print statement
    }
}
int main()
{
    int a = 3;
    func1(a);

    return 0;
}