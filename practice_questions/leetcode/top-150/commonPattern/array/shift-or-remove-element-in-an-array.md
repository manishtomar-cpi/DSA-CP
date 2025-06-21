### Common Pattern for Removing or Shifting Elements

This is a very common and useful pattern when we want to **remove an element** or **shift elements** inside an array without using extra space. 

Here's a simple and clean implementation:

```cpp
int removeEle(vector<int> &nums, int val)
{
    // Time Complexity: O(N), Space Complexity: O(1)
    int i = 0; // Pointer to place the next valid (non-val) element

    for (int j = 0; j < nums.size(); j++)
    {
        // If current element is not equal to the value we want to remove
        if (nums[j] != val)
        {
            // Place the valid element at index 'i' and move 'i' forward
            nums[i++] = nums[j];
        }
        // If it matches 'val', do nothing (we skip it)
    }

    // 'i' is now the new length of the array without 'val' elements
    return i;
}
```

---

### Explanation of the Pattern

- Imagine we are scanning the array from start to end (using `j`).
- We want to skip all values equal to `val` and keep all other values.
- Instead of creating a new array, we just overwrite the unwanted values.
- We use another pointer `i` to mark where to place the next valid number.
- As we loop through the array:
  - If the current number is **not** equal to `val`, we move it to the front (at index `i`).
  - This way, we are pushing all the valid elements to the front of the array.
  - Elements that match `val` are skipped.

 This is efficient because:
- We're not using extra memory (in-place).
- We only go through the array once.

---

### Where You Can Use This Pattern

- **Remove a specific number** from an array.
- **Move zeroes to the end** of an array (by changing the condition).
- **Filter** an array based on a condition (e.g., keep only even numbers).
- **In-place compression** of arrays (like removing duplicates).

