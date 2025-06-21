#include <iostream>
#include <utility>
#include <vector>
using namespace std;
void display_pair(pair<int, int> p)
{
    cout << "[ " << p.first << " " << p.second << " ]" << endl;
}

//Time: O(n), Comparisions: 2n - 2
pair<int, int> getMinMax(vector<int> arr)
{
    int small = INT_MAX; // for small numbers to compare if the current is less then then small, so max will work on index 0 element
    int large = INT_MIN; // same for large the firs tindex should be large then MIN
    pair<int, int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        // check for small
        if (arr[i] < small)
        {
            small = arr[i];
        }
        // check for large
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    res.first = small;
    res.second = large;
    display_pair(res);
    return res;
}

/*
Approach: Optimized Min-Max Using Pairwise Comparison

Goal:
To find the minimum and maximum values in an array using the least number of comparisons.
This approach reduces the total number of comparisons to approximately 1.5 * n,
compared to the standard 2 * n comparisons in a simple linear scan.

Variables used:
- size: total number of elements in the array
- small: stores the minimum value found so far
- large: stores the maximum value found so far
- i: index used for iterating through the array
- local_small, local_large: hold the smaller and larger value of each current pair

Step-by-step logic:

STEP 1: Check if the size of the array is odd or even
    1.1 - If odd:
        - Set both small and large to arr[0], the first element
        - This leaves an even number of elements for the main loop to process in pairs
        - Set i = 1 to start the loop from the next element

    1.2 - If even:
        - Compare the first two elements (arr[0] and arr[1])
        - Assign the smaller one to small and the larger one to large
        - Set i = 2 to start the loop from the third element

STEP 2: Traverse the array from index i to size - 1, incrementing i by 2 each time
    - This allows processing elements in pairs

STEP 3: For each pair (arr[i], arr[i+1]):
    - Compare the two elements with each other first
    - Assign the smaller one to local_small and the larger one to local_large

STEP 4: Update global small and large using the local values
    - If local_small is less than small, update small
    - If local_large is greater than large, update large

Notes:
- This approach avoids unnecessary comparisons
- It ensures no index out-of-bound error by handling odd and even size separately
- Useful when performance matters or during interview problems focused on comparison count

Time: O(n), Comparisions: 1.5n - 2
*/

pair<int, int> getMinMax_2(vector<int> &arr)
{
    int size = arr.size();
    int small;
    int large;
    int i;

    // if size is even then we can easily go pair by pair
    if (size % 2 == 0)
    {
        if (arr[0] < arr[1])
        {
            small = arr[0];
            large = arr[1];
        }
        else
        {
            small = arr[1];
            large = arr[0];
        }
        i = 2;
    }
    else
    {
        small = large = arr[0];
        i = 1;
    }
    while (i < size - 1)
    {
        int local_small;
        int local_large;
        if (arr[i] < arr[i + 1])
        {
            local_small = arr[i];
            local_large = arr[i + 1];
        }
        else
        {
            local_small = arr[i + 1];
            local_large = arr[i];
        }

        if (local_small < small)
            small = local_small;
        if (local_large > large)
            large = local_large;
        i += 2;
    }
    cout << "[ " << small << " " << large << " ]" << endl;
    return {small, large};
}

int main()
{
    vector<int> arr = {1, 5, 2, 8, 10, 14, 17};
    getMinMax_2(arr);

    return 0;
}
