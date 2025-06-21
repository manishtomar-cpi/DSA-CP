#include <iostream>
#include <vector>
using namespace std;

/*
  - Each nums[i] tells the max steps we can jump from index i.
    - We maintain a variable 'reach' which tells the farthest index we can currently reach.
    - At each index, if 'i > reach', it means we are stuck and can't move forward → return false.
    - We update reach using max(reach, i + nums[i]):
        → This ensures we keep the farthest jump possible (don't overwrite good reach with a smaller one).
        → Example: nums = [3, 0, 8, 2, 0, 0, 1]
           - At index 2, nums[2] = 8 → we can jump to index 10 (way ahead).
           - Later, we encounter 0s at index 4 and 5, but we are still safe because reach is already 10.
           - If we didn’t use max(), reach would reduce to 4 or 5, and we would think we’re stuck — but we're not!
           - That’s why we use max() — to remember the best (farthest) jump so far.

    Special Cases:
    - If the first element is 0 and array has more than 1 element, we are stuck at start.
    - If the array has only 1 element, we're already at the last index → return true.


    !Time Complexity: O(n)
    !Space Complexity: O(1)
*/

bool canJump(vector<int> &nums)
{
    if (nums[0] == 0)
    {
        return false;
    }
    if (nums.size() == 1)
    {
        return true;
    }
    int reach = 0; // hold the max reach we can
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > reach)
        { // condition when we encounter '0' anywhere we cant go anywhere from that step then i became larger then reach we cna retuen false example -> [3,2,1,0,4]
            return false;
        }
        reach = max(reach, i + nums[i]); // update rech
        if (reach >= nums.size() - 1)
        { // we can go at last
            return true;
        }
    }
    return false;
}

int main()
{
    vector<int> vec = {3, 2, 1, 0, 4};
    cout << boolalpha;
    cout << canJump(vec) << endl;
    return 0;
}