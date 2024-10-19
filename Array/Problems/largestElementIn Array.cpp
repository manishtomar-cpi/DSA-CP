#include <iostream>
using namespace std;

int largest(int arr[])
{
    int large = arr[0];

    for (int i = 0; i < 6; i++)
    {
        if(arr[i]> large){
            large = arr[i];
        }
    }

    return large;
}

int main()
{
    cout << "hello" << endl;
    int arr[6] = {3, 6, 1, 4, 9, 8};
    cout << largest(arr) << endl;
}

// int large  = arr[0];
// loop(i = last){
//  if (arr[i]> large{
//  large = arr[i]})}