#include <iostream>
#include <vector>
using namespace std;

//removing all the occur of the val
int removeElement(vector<int> &nums, int val)
{ //? TIME: O(N), SPACE: O(1)
    if (nums.size() == 0)
    {
        return 0;
    }
    int i = 0;
    int j = nums.size() - 1;
    while (i <= j)
    {
        if (nums[i] == val)
        {
            swap(nums[i], nums[j]);
            nums[j--] = INT16_MAX;
            continue;
        }
        i++;
    }
    return i;
}

//! WITHOUT SWAP
int removeEle(vector<int> &nums, int val)
{              //? TIME: O(N), SPACE: O(1)
    int i = 0; // for store the non matching element
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != val) // we are only checking the non matching elements
        {
            // so now , we can skip the matching number, and matching num is override by the next non matching number
            nums[i++] = nums[j];
        }
    }
    return i;
}

int main()
{
    vector<int> vec = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    cout << removeEle(vec, val) << endl;

    return 0;
}