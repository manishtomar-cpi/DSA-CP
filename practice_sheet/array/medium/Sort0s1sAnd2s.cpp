#include <iostream>
#include <vector>
using namespace std;
void display(vector<int> &arr)
{
    cout << "[ ";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
}

/*
Approach: Custom Two-Pass Algorithm to Sort an Array of 0s, 1s, and 2s

Goal:
To sort an array containing only 0s, 1s, and 2s in ascending order (all 0s first, then 1s, then 2s).

Concept:
This is a variant of the Dutch National Flag problem, but implemented using two separate passes instead of a single scan.

Step-by-step explanation:

Step 1: First pass – Move all 0s to the beginning
    - Use two pointers: i (current index), and j (boundary of last placed 0)
    - Initialize j = -1
    - Loop from i = 0 to end of array:
        - If arr[i] is 0, increment j and swap arr[i] with arr[j]
        - This keeps all 0s at the start in-place

Step 2: Second pass – Move all 1s just after the 0s
    - Reset i = 0 and j = 0 again
    - Use a boolean flag `checked` to mark when we first encounter a 2
    - Loop through the array again:
        - When a 2 is first found, set j = i and checked = true
        - Then for every 1 after that, swap it with arr[j], and increment j
    - This shifts 1s just after the 0s and pushes 2s to the end

Important Notes:
- This code assumes the array only contains 0s, 1s, and 2s
- It works in O(n) time and does the sorting in-place
- It’s slightly more manual than the standard Dutch National Flag algorithm but works correctly for this specific input type
- Make sure to test with edge cases like all 0s, all 2s, or no 1s

Example:
Input: [2, 0, 2, 1, 1, 0]
After Pass 1: [0, 0, 2, 1, 1, 2]
After Pass 2: [0, 0, 1, 1, 2, 2]

Another solution in more then one pass:
count the number of 0,1,2 in first pass
in second pass fill the array accordingly 
*/

void sort012(vector<int> &arr)
{
    int i = 0;  //--> aage chalega
    int j = -1; // --> piche
    // first pass
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            // increment j, because j is at index which contain 0, so for next 0 we do j++ first;
            j++;
            swap(arr[i], arr[j]);
        }
    }

    // use these i and j again why from zero? because now we will check for 1 and 2 and in general case we have 0 at first positions for special cases when no zero in the array we use the checked flag
    i = 0;                //-->aage
    j = 0;                //--> piche
    bool checked = false; // for [2 2 1 1 1 2 1 2 1] these cases which dont have 0
    for (int i = 0; i < arr.size(); i++)
    {
        // first see  the first 2 in array after getting point j to that point because this is the position where we will swap next 1
        if (arr[i] == 2 && !checked)
        {
            j = i;
            checked = true;
        }

        // when we get next 1 and we already move j, means j is on the index which contain 2 swap it
        if (arr[i] == 1 && checked)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
    display(arr);
}
int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 1, 2, 1};

    sort012(arr);
    return 0;
}