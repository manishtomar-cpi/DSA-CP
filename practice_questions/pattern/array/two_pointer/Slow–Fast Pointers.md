# Pattern: Two Pointers – Slow and Fast

This pattern is used when we need to **traverse an array and perform in-place operations** such as filtering, removing, or rearranging elements **based on a condition**.

---

## How It Works

- **Fast Pointer (`i`)**: Scans every element of the array.
- **Slow Pointer (`j`)**: Tracks the position where the next valid element should go.
- **Condition**: Applied to decide whether the current element should be kept or ignored.

---

## Use Cases

- In-place filtering or deletion
- Preserving or rearranging relative order (if required)
- Avoiding extra space (O(1) space)

---

## Example Problem: Remove Element

> Remove all occurrences of `val` from `nums` in-place and return the new length.

### Problem File:  
[`removeElement.cpp`](../../../leetcode//top-150/array-string/easy/removeElement.cpp)

### Solution Using Slow–Fast Pointers:

```cpp
int j = 0;
for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != val) {
        nums[j++] = nums[i];
    }
}
return j;

```

### Similar Questions 

| Problem                                           | Description                                                                 |
|--------------------------------------------------|-----------------------------------------------------------------------------|
| [Move Zeroes](https://leetcode.com/problems/move-zeroes/) | Shift all non-zero elements to the front and fill the rest with 0s.         |
| [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | Keep only one occurrence of each value in a sorted array.                  |
| [Sorted Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/) | Return squares of sorted array in sorted order (can use slow-fast variation or start-end). |
| [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/) | Variant of overwrite-based in-place removal.                               |
| [Compress String](https://leetcode.com/problems/string-compression/) | Use two pointers to compress a character array in-place.                   |
