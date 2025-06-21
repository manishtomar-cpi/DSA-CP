#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        //.count() function give if the element is present or not in the map -> why we use this? if we use hash[nums[i]]==0 that will crash some time because the first element is in the '0th' index so first_element -> 0 is stored and the condition will ignored it
        if (hash.count(nums[i]) && (i - hash[nums[i]]) <= k)
        {

            return true;
        }
        // store the index
        hash[nums[i]] = i;
    }
    return false;
}

/*
  Problem: Contains Nearby Duplicate

  Given an array 'nums' and an integer 'k',
  return true if there are two indices i and j such that:
    - nums[i] == nums[j]
    - abs(i - j) <= k

  --------------------------------------------
  Approach: Hash Map (Value → Last Seen Index)
  --------------------------------------------
  - Use an unordered_map to store the last seen index of each number.
  - For each number:
      1. If it was seen before (i.e., already in map)
         → check if the distance between current and last index ≤ k
         → if yes, return true
      2. Otherwise, or if distance > k
         → update the map with the current index
  - If we finish the loop without finding such a pair → return false

  !Time Complexity: O(n)
  !Space Complexity: O(n)
*/
int main()
{
    vector<int> nums = {1, 2, 3, 1, 2, 3};
    cout << boolalpha;
    int k = 2;
    cout << containsNearbyDuplicate(nums, k) << endl;

    return 0;
}