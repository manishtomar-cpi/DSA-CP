#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// simple swap with two pointers approach
void reverse_1(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}
// we can solve this by iterate till first half of array by swapping from 'arr.size() - 1' - 'i' (corresponding element from the end) because we swap the first half element with seond half of list
void reverse_2(vector<int> &arr)
{
    int size = arr.size() - 1;
    int i = 0;
    while (i < (size / 2))
    {
        swap(arr[i], arr[size - i]);
        i++;
    }
}

//? from recusion, TIME: O(N), SPACE O(N) because for recusrion stack
void recerse_3_by_recusrion(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    swap(arr[left], arr[right]);
    recerse_3_by_recusrion(arr, left + 1, right - 1);
}

// function to reverse an array in STL
void reverse_4_STL(vector<int> &arr)
{
    reverse(arr.begin(), arr.end());
}

void print_array(vector<int> &vec)
{
    cout << "[ ";
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    recerse_3_by_recusrion(arr2,0,arr2.size()-1);
    print_array(arr2);
}