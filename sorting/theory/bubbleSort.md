### Bubble Sort

Bubble Sort is a simple comparison-based sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list becomes sorted.

#### **Steps of Bubble Sort:**
1. Start from the beginning of the list and compare the first two elements.
2. If the first element is greater than the second, swap them.
3. Move to the next pair of adjacent elements and repeat the comparison and swapping if needed.
4. Continue this process for all elements in the list. After one full pass, the largest element "bubbles" to its correct position at the end of the list.
5. Repeat steps 1–4 for the remaining unsorted portion of the list until no swaps are required.

#### **Key Characteristics:**
- **Comparison-Based:** Compares adjacent elements.
- **In-Place Sorting:** Requires no extra space, so the space complexity is \( O(1) \).
- **Stable Algorithm:** Preserves the relative order of equal elements.
- **Time Complexity:**
  - **Best Case:** \( O(n) \) (when the list is already sorted, with an optimized implementation).
  - **Average Case:** \( O(n^2) \).
  - **Worst Case:** \( O(n^2) \).
- **Space Complexity:** \( O(1) \) since it only uses a constant amount of extra memory.

#### **Example (Ascending Order):**
Consider the array: **[4, 3, 2, 1, 1, 1, 9, 7, -9]**

1. **First Pass:**
   - Compare and swap (4, 3): [**3**, **4**, 2, 1, 1, 1, 9, 7, -9]
   - Compare and swap (4, 2): [3, **2**, **4**, 1, 1, 1, 9, 7, -9]
   - Compare and swap (4, 1): [3, 2, **1**, **4**, 1, 1, 9, 7, -9]
   - Continue for the rest of the list, moving the largest number (9) to the end.

2. **Second Pass:**
   - Repeat the comparisons and swaps for the remaining unsorted portion: [**1**, **3**, 2, 1, 1, 4, 7, 9, -9]

3. **Subsequent Passes:**
   - Each pass places the next largest element in its correct position.

After all passes, the array becomes **[-9, 1, 1, 1, 2, 3, 4, 7, 9]**.

#### **Choosing the Number of Iterations:**
In Bubble Sort, the number of iterations required depends on the size of the input list, \( n \). In the worst case (when the list is sorted in reverse order), the algorithm performs \( n-1 \) passes through the list. Here's why:

- After the first pass, the largest element is guaranteed to be in its correct position.
- After the second pass, the second largest element is in its correct position, and so on.
- Therefore, for a list of size \( n \), the algorithm requires \( n-1 \) passes to ensure all elements are sorted.

If the list becomes sorted before completing all \( n-1 \) passes, the algorithm can be optimized by introducing a **flag** to check whether any swaps occurred during a pass. If no swaps occur, the algorithm can terminate early, as the list is already sorted.

#### **Advantages:**
- Easy to understand and implement.
- Works well on small datasets or nearly sorted data (with an optimized version).

#### **Disadvantages:**
- Inefficient on large datasets due to \( O(n^2) \) complexity.
- Multiple passes through the list increase execution time.
