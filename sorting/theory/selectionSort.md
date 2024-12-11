### Selection Sort

Selection Sort is a simple comparison-based sorting algorithm that works by dividing the list into two parts: a sorted portion and an unsorted portion. It iteratively selects the smallest (or largest, depending on the sorting order) element from the unsorted portion and swaps it with the first element of the unsorted portion, thereby growing the sorted portion by one element.

#### **Steps of Selection Sort:**
1. Start with the entire list as unsorted.
2. Find the smallest (or largest) element in the unsorted portion of the list.
3. Swap this smallest element with the first element of the unsorted portion.
4. Move the boundary between the sorted and unsorted portions one element forward.
5. Repeat steps 2–4 until the unsorted portion has only one element left.

#### **Key Characteristics:**
- **Comparison-Based:** The algorithm repeatedly compares elements to find the smallest (or largest) element in the unsorted portion.
- **In-Place Sorting:** It does not require extra space for another array, so the space complexity is \( O(1) \).
- **Stable or Unstable:** The basic implementation is unstable (it may change the relative order of equal elements), but it can be made stable.
- **Time Complexity:**
  - **Best Case:** \( O(n^2) \)
  - **Average Case:** \( O(n^2) \)
  - **Worst Case:** \( O(n^2) \)
- **Space Complexity:** \( O(1) \) since it only uses a constant amount of extra memory.

#### **Example (Ascending Order):**
Consider the array: **[7, 5, 3, 1, 6, 8, 2]**

1. **First Pass:** Find the smallest element (1) and swap it with the first element:
   - [**1**, 5, 3, **7**, 6, 8, 2]
2. **Second Pass:** Find the smallest in the unsorted portion ([5, 3, 7, 6, 8, 2]) and swap with the second element:
   - [1, **2**, 3, 7, 6, 8, **5**]
3. **Third Pass:** Find the smallest in the unsorted portion ([3, 7, 6, 8, 5]) and swap with the third element:
   - [1, 2, **3**, 7, 6, 8, 5]
4. Continue until the array is sorted:
   - [1, 2, 3, **5**, 6, 8, **7**]
   - [1, 2, 3, 5, **6**, 7, **8**]

After all passes, the array becomes **[1, 2, 3, 5, 6, 7, 8]**.

#### **Advantages:**
- Simple to understand and implement.
- Works well for small datasets.

#### **Disadvantages:**
- Inefficient on large lists due to \( O(n^2) \) complexity.
- Does not adapt to partially sorted lists.
