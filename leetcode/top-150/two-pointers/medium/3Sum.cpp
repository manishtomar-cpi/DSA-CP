#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    set<vector<int>> unique;
    if (nums.size() < 3)
    {
        return {};
    }
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    unique.insert(triplet);
                }
            }
        }
    }

    for (auto t : unique)
    {
        res.push_back(t);
    }
    return res;
}

int main()
{
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    threeSum(vec);

    return 0;
}