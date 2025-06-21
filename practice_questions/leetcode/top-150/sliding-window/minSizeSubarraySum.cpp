#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{ //! TIME O(N^2)
    if (nums.size() == 0)
    {
        return 0;
    }
    int sum = 0;
    int size = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum >= target)
        {
            return 1;
        }
        int currentSize = 1;
        for (int j = i + 1; j < nums.size(); j++)
        {
            currentSize++;
            sum += nums[j];
            if (sum >= target)
            {
                if (size == 0)
                {
                    size = currentSize;
                }
                else
                {
                    size = min(size, currentSize);
                }
                sum = 0;
            }
            break;
        }
        sum = 0;
    }
    return size;
}
/*
Approach: Sliding Window (Two Pointers)
    1. Initialize two pointers:
       - `left`: start of the sliding window
       - `right`: end of the sliding window (loop variable)

    2. Use a variable `sum` to keep track of the current window sum.

    3. Expand the window by moving `right` and adding `vec[right]` to `sum`.

    4. While `sum` is greater than or equal to the target:
       - Update `min_len` with the smaller of current `min_len` and window size.
       - Shrink the window from the left by subtracting `vec[left]` and incrementing `left`.

    5. After the loop, if no valid subarray was found, return 0.
       Otherwise, return the minimum length found.

    Time Complexity: O(n) — each element is visited at most twice.
    Space Complexity: O(1)
*/
int minSubArrayLen_2(int target, vector<int> &vec)
{                 //! TIME:O(N), SPACE:O(1)
    int left = 0; // for resizing window to right
    int sum = 0;  // for calculate total sum
    int min_len = INT16_MAX;

    // iterating the vector from right
    for (int right = 0; right < vec.size(); right++)
    {
        // calculating sum -> expand window
        sum += vec[right];

        // if sum became greater then target then shift the window to right and calculate len in each step till we get the actual min len
        while (sum >= target)
        {
            min_len = min(min_len, right - left + 1);
            sum -= vec[left++];
        }
        // then again add next [ith] value and follow the same process
    }
    return min_len == INT16_MAX ? 0 : min_len;
}
int main()
{
    int target = 7;
    vector<int> vec = {2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen_2(target, vec) << endl;

    return 0;
}