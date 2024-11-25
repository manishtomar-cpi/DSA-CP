#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void understandRef(vector<int> &vec)
{
    for (int &i : vec)
    {
        cout << i << endl;
        if (i == 2)
        {
            i = 10; // change first index because its by ref
        }
    }
}

int main()
{
    // int arr[10] = {1, 2, 3};
    // cout << arr[3] << endl; // return '0' because we init the array

    // int arr2[10] = {1, 4, 6}; // 1,4,6,0,0.... -> because define some values
    // for (auto &i : arr2)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // int arr3[10];
    // cout << sizeof(arr3) << endl; // 40

    vector<int> vec = {1, 2, 3, 5};
    understandRef(vec);
    cout << endl;
    cout << "check" << endl;
    cout << vec[1]; // 10
    return 0;
}