#include <iostream>
#include <vector>
using namespace std;

int pivot(vector<int> &nums)
{
    //! BF Approach
    // if ((nums.size() == 2 && nums.at(1) == 0))
    // {
    //     return 0;
    // }
    // int leftSum = 0;
    // int rightSum = 0;

    // for(int i = 1;i<nums.size();i++){
    //     rightSum +=nums.at(i);
    // }
    // if(rightSum==0){
    //     return 0;
    // }
    // rightSum =0;

    // for (int i = 0; i < nums.size()-1; i++)
    // {

    //     leftSum += nums.at(i);
    //     for (int j = i + 2; j < nums.size(); j++)
    //     {
    //         rightSum += nums.at(j);
    //     }
    //     if (leftSum == rightSum)
    //     {
    //         return i + 1;
    //     }
    //     else
    //     {
    //         rightSum = 0;

    //     }
    // }
    // return -1;
    //! optimised
    int total = 0;
    int leftTotal = 0;
    int rightTotal = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        total += nums.at(i);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        rightTotal = total - leftTotal - nums[i]; //*we are subtracting nums[i]  because it is also the part of total and we wants the sum on the right of the nums[i] = left of the nums[i]
        if (rightTotal == leftTotal)
        {
            return i;
        }
        leftTotal += nums[i];
    }
    return -1;
}

int main()
{
    vector<int> vec = {1,7,3,6,5,6};
    cout << pivot(vec);

    return 0;
}
