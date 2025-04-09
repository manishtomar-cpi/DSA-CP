#include <iostream>
#include <vector>
using namespace std;

/*
    Approach:
    - Since the input array is sorted in non-decreasing order, use the two-pointer technique.
    - Initialize one pointer `i` at the beginning and another `j` at the end of the array.
    - Calculate the sum of numbers[i] + numbers[j].
        - If the sum equals the target, return the 1-based indices [i+1, j+1].
        - If the sum is less than the target, move the left pointer `i` forward to increase the sum.
        - If the sum is greater than the target, move the right pointer `j` backward to decrease the sum.
    - Repeat until the correct pair is found.
    !- This approach runs in O(n) time and uses constant O(1) extra space.
    */

vector<int> twoSum(vector<int> &numbers, int target)
{
    int i = 0;
    int j = numbers.size() - 1;
    while (i < j)
    {
        if (numbers[i] + numbers[j] == target)
        {
            return {i + 1, j + 1};
        }
        else if (numbers[i] + numbers[j] < target)
        {
            i++;
            continue;
        }
        else
        {
            j--;
            continue;
        }
    }
    return {};
}

int main()
{
    vector<int> vec = {2, 7, 11, 13};
    twoSum(vec, 9);

    return 0;
}