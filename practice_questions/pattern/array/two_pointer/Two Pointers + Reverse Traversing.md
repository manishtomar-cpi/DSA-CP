# Pattern: Two Pointers + Reverse Traversing

Used when traversing two sorted arrays from the back (right to left), especially for in-place merging without using extra space.

---

## Problems Using This Pattern

### [Merge Sorted Array - Example Question](../../../leetcode/top-150/array-string/easy/mergeSortedArray.cpp)

- **Topic**: Array
- **Difficulty**: Easy
- **Leetcode Link**: [https://leetcode.com/problems/merge-sorted-array/](https://leetcode.com/problems/merge-sorted-array/)
- **Insight**: Compare from the end using two pointers and insert values from the back of `nums1`.
- **Learning**: Helps build intuition for in-place merging and pointer movement from the rear.

---

## When to Use

- Merging sorted arrays **in-place**
- Avoiding extra space for merging
- Comparing elements from the **end** of arrays
- Working with **sorted arrays**

---

## Related Problems

- [ ] [Two Sum II – Input Array Is Sorted](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
- [ ] [Reverse Vowels of a String](https://leetcode.com/problems/reverse-vowels-of-a-string/)
- [ ] [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)