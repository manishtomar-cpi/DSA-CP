#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    // for(int i =0 ;i<nums.size();i++){
    //     if(nums[i]==target){
    //         return i;
    //     }
    // }
    // return -1;
    int low = 0;
    int high = nums.size()-1;
    int mid = (low+high)/2;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] < nums[i])
        {
            if (target > nums[0])
            {
                low = 0;
                high = i;
                mid = (low + high) / 2;
                break;
            }
            if (target < nums[0])
            {
                low = i + 1;
                high = nums.size() - 1;
                mid = (low + high) / 2;
                break;
            }
            if(target==nums[0]){
                return 0;
            }
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[mid] == target)
        {
            return mid;
            break;
        }
        if (nums[mid] > target)
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
        if (nums[mid] < target)
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
    }
    return -1;
}

int main()
{
    vector<int> vec = {5,1, 3};

    cout << search(vec, 5);

    return 0;
}