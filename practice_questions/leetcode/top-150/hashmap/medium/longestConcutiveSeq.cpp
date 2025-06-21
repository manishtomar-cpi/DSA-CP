#include <iostream>
#include <map>
#include <vector>

using namespace std;

void display(vector<int> &str)
{
    cout << "[ ";
    for (auto i : str)
    {
        cout << i << " , ";
    }
    cout << "]" << endl;
}

/*
  Find the length of the longest consecutive elements sequence in an unsorted array.
  The sequence must be consecutive numbers (like 1,2,3,4), not necessarily in order.

  Approach (Sorted Unique Map-based):
  -------------------------------------
  1. Use a map<int, int> to store all unique numbers from the input array.
     → map keeps the keys automatically sorted.
  2. Transfer the sorted keys into a vector<int> called 'uniques'.
     → This will be the list of unique, sorted values from the original array.
  3. Traverse the 'uniques' vector and find the longest streak of consecutive numbers.
     → Whenever the current number is NOT one more than the previous, reset the streak.
     → Keep track of the longest streak using two pointers: 'first' and 'second'.

  Note:
  - We cast uniques.size() to int at the end to avoid signed/unsigned mismatch with 'first'.

  !Time Complexity: O(n log n) due to map insertion
  !Space Complexity: O(n)
*/


int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    int maxLen = INT16_MIN;
    vector<int> uniques;
    map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++;
    }
    for (auto i : hash)
    {
        uniques.push_back(i.first);
    }
    display(uniques);
    int first = 0;
    for (int second = 1; second < uniques.size(); second++)
    {
        if (uniques[second] != uniques[second - 1] + 1)
        {
            maxLen = max(maxLen, second - first);
            first = second;
        }
    }
    // .size() returns size_t (unsigned), cast to int to safely subtract with signed variables
    maxLen = max(maxLen, (int)uniques.size() - first); // That handles the final group at the end and ensures correct edge case handling.
    return maxLen;
}

int main()
{
    vector<int> vec = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    cout << longestConsecutive(vec) << endl;

    return 0;
}
