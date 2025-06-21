#include <iostream>
#include <vector>
using namespace std;

/*
    Greedy Approach Explanation:

    - The problem is to find two lines that, along with the x-axis, form a container holding the most water.
    - Since the area depends on the shorter of the two heights and the distance between them,
      we use a greedy strategy to always choose the better possibility at each step.

    Why it's greedy:
    - We start with the two farthest lines (leftmost and rightmost), which give us the widest possible container.
    - At each step, we compute the area and try to improve it by greedily moving the pointer pointing to the shorter line:
        - Because the current area is limited by the shorter height, moving it might lead to a taller line,
          which can potentially increase the area even if the width decreases.
        - We never move the taller line because doing so cannot help improve the result — it would only reduce width
          without gaining height.
    - This way, we greedily make the best local choice (taller potential) in hopes of getting the global maximum.

    MaxArea= height * distance -> here we will take min distance because water cannnot slant(go above) that's why we took min(first, second)*(first-second)

    !Time Complexity: O(n)
    !Space Complexity: O(1)
    */

int maxArea(vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;
    int totalArea = 0;
    while (i < j)
    {
        int currentArea = min(height[i], height[j]) * (j - i);
        totalArea = max(totalArea, currentArea);
        if (height[i] < height[j])
        {
            i++; // Move the shorter line to try and find a taller one
        }
        else
        {
            j--; // Move the shorter line from the right side
        }
    }
    return totalArea;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;

    return 0;
}