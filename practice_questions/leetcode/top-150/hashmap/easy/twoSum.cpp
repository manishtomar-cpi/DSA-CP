#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hash;
    /*
    storing the index of all the elements like,
    2 -> 0
    7 -> 1
    11 -> 2
    15-> 3
    */
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]] = i;
    }

    vector<int> res;

    for (int i = 0; i < nums.size(); i++)
    {
        // the number we want
        int want = target - nums[i];

        // if that in the map and not used (INT_MAX)
        if (hash[want] != 0 && hash[want] != INT_MAX)
        {
            // not taking the current index, if 3 is on 'ith' index and target is 6, so it should not take current 3 index from map;
            if (hash[want] != i)
            {
                res.push_back(i);
                res.push_back(hash[want]);
                hash[nums[i]] = INT_MAX;
                cout << "[ " << i << " , " << hash[want] << " ]" << endl;
            }
        }
    }
    return res;
}

int main()
{
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;
    twoSum(vec, target);

    return 0;
}
