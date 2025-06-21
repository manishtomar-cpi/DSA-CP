#include <iostream>
#include <vector>
using namespace std;

// remove all duplicated of an element
int removeDuplicates(vector<int> &nums)
{ //?TIME: O(N), SPACE: O(N)
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return 1;

    int i = 0;
    int j = 1;
    while (j < nums.size())
    {
        if (nums[i] == nums[j])
        {
            nums[j++] = INT16_MAX;
            continue;
        }
        i = j;
        j++;
    }
    i = 0;
    j = 0;
    for (j; j < nums.size(); j++)
    {
        if (nums[j] != INT16_MAX)
        {
            nums[i++] = nums[j];
        }
    }
    return i;
}

//! IN SINGLE TRAVERSAL
int removeDupOptimize(vector<int> &nums)
{
    int i = 0; // slow pointer for the next unique position
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] != nums[i])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i++;
}

int main()
{
    vector<int> vec = {1, 2, 2};
    cout << removeDuplicates(vec) << endl;

    return 0;
}