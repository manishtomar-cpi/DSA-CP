#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int> &nums)
{
    //! TIME : O(N) SPACE: O(N) -> because of newly created map
    // unordered_map<int, int> hash;
    // for (int i = 0; i < nums.size(); i++) {
    //     hash[nums[i]]++;
    //     if (hash[nums[i]] > nums.size() / 2) {
    //         return nums[i];
    //     }
    // }
    // return 0;

    //! Moore's voting approach
    //! TIME: O(N), SPACE:O(1)
    int count = 0;
    int majority = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == majority)
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                majority = nums[i];
                count++;
            }
        }
    }

    return majority;
}

int main()
{
    vector<int> vec = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(vec) << endl;

    return 0;
}