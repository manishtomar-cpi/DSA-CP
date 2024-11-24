#include <iostream>
#include <algorithm>
using namespace std;

void reverseArray(int arr[], int size)
{
    int j = size-1;

    cout << "orignal array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "after reverse" << endl;

    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[j]);
        j--;
    }
   
       for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main (){
    int arr[5]= {1,5,6,7,8};

    reverseArray(arr, 5);

    return 0;
}