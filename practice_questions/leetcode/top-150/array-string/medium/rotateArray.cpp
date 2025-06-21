#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &vec)
{
    cout << "[ ";
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}
/*
1. Reverse the Entire Array
    Reversing the whole array places the elements in reverse order.
    Example:
        Input: [1, 2, 3, 4, 5, 6, 7] → Reversed: [7, 6, 5, 4, 3, 2, 1]
2- Normalize the Rotation Count
    If k is larger than the array size (n), rotating k times is equivalent to rotating k % n times.
    Example:
        For an array of size 8, rotating 10 times is the same as rotating 10 % 8 = 2 times.
3- Reverse the First k Elements
    This puts the elements that were originally at the end into their correct rotated positions.
    Continuing our example:
        Reverse first k = 3 elements of [7, 6, 5, 4, 3, 2, 1] → [5, 6, 7, 4, 3, 2, 1]
4- Reverse the Remaining n - k Elements
    This puts the remaining part of the array back in order.
    Final step:
        Reverse elements from index k to end → [5, 6, 7, 1, 2, 3, 4]
*/
void rotateArray(vector<int> &nums, int k)
{ //! TIME: O(N), SPACE: O(1)
    if (nums.size() == 0)
    {
        return;
    }
    int i = 0;
    int j = nums.size() - 1;

    // reversing the array
    while (i < j)
    {
        swap(nums[i++], nums[j--]);
    }
    display(nums);

    // Normalize the Rotation Count
    int rorationTime = k % nums.size(); // If k is larger than the array size (n), rotating k times is equivalent to rotating k % n times.
    i = 0;
    j = rorationTime - 1;

    // Reverse the First k Elements
    while (i < j)
    {
        swap(nums[i++], nums[j--]);
    }
    display(nums);

    // Reverse the Remaining n - k Elements
    i = rorationTime;
    j = nums.size() - 1;

    while (i < j)
    {

        swap(nums[i++], nums[j--]);
    }
    display(nums);
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    int k = 8;
    rotateArray(vec, k);

    return 0;
}