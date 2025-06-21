#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Approach: Brute Force to Find the Kth Smallest Element

Goal:
To find the kth smallest element in an unsorted array without using sorting.

Concept:
We check how many elements in the array are smaller than each element.
If the count of smaller elements becomes exactly (k - 1), then that element is the kth smallest.

Variables:
- arr: input vector of integers
- k: the position of the smallest element to find (1-based index)
- current: the element being considered as a potential kth smallest
- count: number of elements smaller than the current element

Step-by-step logic:

Step 1: Loop through each element of the array using index i
    - Set current = arr[i]
    - Initialize count = 0

Step 2: For each current element, loop through the entire array using index j
    - If arr[j] < arr[i], increment count

Step 3: After inner loop ends, check if count == (k - 1)
    - If true, it means exactly (k - 1) elements are smaller than current
    - Therefore, current is the kth smallest element
    - Return current

Notes:
- This is a brute-force method, so it checks all possible conditions by comparing every pair
- Time complexity is O(n^2), which is inefficient for large arrays
- Useful for understanding basic logic and for small input sizes
*/

int kthSmallest(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int current = arr[i];
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] < arr[i])
            {
                count++;
            }
        }
        if (count == (k - 1))
        {
            return current;
        }
    }
    return -1;
}

/*
Approach: Find Kth Smallest Element Using Max-Heap (Priority Queue)

Goal:
To find the kth smallest element in an unsorted array efficiently using a heap-based method.

Key Concept:
We use a max-heap to keep track of the k smallest elements seen so far. 
The largest of these k elements is always at the top of the max-heap.
After processing the full array, the top of the heap will be the kth smallest element.

Why a max-heap:
- We want to maintain the smallest k elements.
- If a new element is smaller than the current largest of the k smallest (heap top), we replace it.
- This keeps the heap always limited to the smallest k elements.

Variables:
- arr: input vector of integers
- k: the position of the smallest element to find (1-based index)
- heap: a max-heap (priority_queue in C++) storing up to k elements

Step-by-step logic:

Step 1: Traverse the array from index 0 to arr.size() - 1
    - Push the current element into the heap

Step 2: If the heap size exceeds k
    - Pop the largest element (heap.top()), which is no longer among the k smallest

Step 3: After processing all elements, the top of the heap is the kth smallest element
    - Return heap.top()

Time Complexity:
- Each push/pop in the heap takes O(log k)
- For n elements, total time = O(n log k)
- This is much faster than sorting (O(n log n)) when k is small compared to n

Space Complexity:
- O(k) for storing the heap

Notes:
- This method handles duplicate values correctly
- Efficient when only the kth smallest is needed, not the full sorted array
- Suitable for large datasets when k is much smaller than n
*/

int kthSmallest_2(vector<int> &arr, int k)
{
    priority_queue<int> heap;

    for (int i = 0; i < arr.size(); i++)
    {
        heap.push(arr[i]);
        if (heap.size() > k)
        {
            heap.pop();
        }
    }

    return heap.top();
}

int main()
{
    vector<int> arr = {2, 5, 1, 6, 4, 8, 9, 11, 10};
    cout << kthSmallest_2(arr, 5) << endl;
    return 0;
}