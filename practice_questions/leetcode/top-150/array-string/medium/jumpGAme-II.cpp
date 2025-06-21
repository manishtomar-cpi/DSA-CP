#include <iostream>
#include <vector>
using namespace std;

/*
    Greedy Logic to Solve:
    Step-by-step human-style intuition:
    1. You're at index 0.
       From nums[0], you can jump up to nums[0] steps ahead — so explore that range.
    2. Now explore each index within that range (i.e., index 1 to currentEnd).
       While you're walking through these indices, keep track of the farthest index you can reach
       from any of these positions.
    3. Once you reach the end of your current range (i.e., currentEnd == i):
       You've explored all possible options with your current jump.
       Time to jump again: increment the jump counter.
       Set your new currentEnd = farthest you've calculated so far.
    4. Repeat this process until you reach or go beyond the last index.

    Visual Example: nums = [2, 3, 1, 1, 4]

    Step | Index | Value | Reachable | Farthest So Far | Jump Count
    ---------------------------------------------------------------
     1   |   0   |   2   |   0→2     | max(0, 0+2)=2   | Jump when i == 0 → Jump Count = 1
     2   |   1   |   3   |   1→4     | max(2, 1+3)=4   | Jump when i == 2 → Jump Count = 2
     3   |   2   |   1   |           | farthest already planned = 4 (goal)

    We reached or passed the last index — done

    In Plain Words:
    - Go index by index within your current jump window
    - Find the farthest place you can go next
    - Once you reach the end of your jump window, make a jump to that farthest point
    - Repeat until you reach the end
*/

int jump(vector<int> &nums)
{
    int jump = 0;
    int currentEnd = 0; // to store the current max we can reach
    int maxReach = 0;   // to store the max reach we can go, while we are traversing according to the currentEnd
    for (int i = 0; i < nums.size() - 1; i++)
    {
        maxReach = max(maxReach, i + nums[i]); // calculate max we can go from this point
        if (i == currentEnd)                   // when reached to the max
        {
            // jump one step to max reach we can in b/w previous and previous End
            currentEnd = maxReach;
            jump++;
        }
    }
    return jump;
}

int main()
{
    vector<int> vec = {2, 3, 1, 1, 4};

    cout << jump(vec) << endl;

    return 0;
}