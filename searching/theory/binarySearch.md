### Binary Search

Binary Search is an efficient algorithm used to find the position of a target element (key) in a sorted array or list. It works by repeatedly dividing the search interval in half and narrowing down the possible location of the target.

#### **Preconditions:**
1. The input list must be sorted.
2. The search key must be defined.

#### **Steps of Binary Search:**
1. Define two pointers:
   - **Start**: Initially set to the first index (0).
   - **End**: Initially set to the last index (size - 1).
2. Compute the middle index (**mid**) using the formula:
   \[
   \text{mid} = \left\lfloor \frac{\text{start} + \text{end}}{2} \right\rfloor
   \]
3. Compare the middle element (**vec[mid]**) with the key:
   - **Case 1**: If \( \text{vec[mid]} == \text{key} \), the key is found, and the algorithm terminates.
   - **Case 2**: If \( \text{vec[mid]} > \text{key} \), narrow the search to the left half by setting \( \text{end} = \text{mid} - 1 \).
   - **Case 3**: If \( \text{vec[mid]} < \text{key} \), narrow the search to the right half by setting \( \text{start} = \text{mid} + 1 \).
4. Repeat steps 2 and 3 until \( \text{start} > \text{end} \), which means the key is not present in the list.

#### **Termination Conditions:**
1. **Key is found:**
   - The loop exits when \( \text{vec[mid]} == \text{key} \), and the function returns the index \( \text{mid} \).
2. **Key is not found:**
   - The loop terminates when \( \text{start} > \text{end} \). At this point, the key is confirmed to be absent, and the function returns \( -1 \).

#### **Example:**
Given the sorted array: **[0, 1, 2, 3, 4, 5, 7, 9, 10, 12]**
- Search for key \( 7 \):

1. **First Iteration:**
   - Start = 0, End = 9
   - Mid = \( \left\lfloor \frac{0 + 9}{2} \right\rfloor = 4 \)
   - vec[4] = 4 (not equal to 7).
   - Since \( \text{vec[mid]} < \text{key} \), update \( \text{start} = \text{mid} + 1 = 5 \).

2. **Second Iteration:**
   - Start = 5, End = 9
   - Mid = \( \left\lfloor \frac{5 + 9}{2} \right\rfloor = 7 \)
   - vec[7] = 9 (not equal to 7).
   - Since \( \text{vec[mid]} > \text{key} \), update \( \text{end} = \text{mid} - 1 = 6 \).

3. **Third Iteration:**
   - Start = 5, End = 6
   - Mid = \( \left\lfloor \frac{5 + 6}{2} \right\rfloor = 5 \)
   - vec[5] = 7 (equal to the key).
   - Key is found, and the algorithm terminates, returning the index \( 5 \).

- Search for key \( 8 \):

1. **First Iteration:**
   - Start = 0, End = 9
   - Mid = \( \left\lfloor \frac{0 + 9}{2} \right\rfloor = 4 \)
   - vec[4] = 4 (not equal to 8).
   - Since \( \text{vec[mid]} < \text{key} \), update \( \text{start} = \text{mid} + 1 = 5 \).

2. **Second Iteration:**
   - Start = 5, End = 9
   - Mid = \( \left\lfloor \frac{5 + 9}{2} \right\rfloor = 7 \)
   - vec[7] = 9 (not equal to 8).
   - Since \( \text{vec[mid]} > \text{key} \), update \( \text{end} = \text{mid} - 1 = 6 \).

3. **Third Iteration:**
   - Start = 5, End = 6
   - Mid = \( \left\lfloor \frac{5 + 6}{2} \right\rfloor = 5 \)
   - vec[5] = 7 (not equal to 8).
   - Since \( \text{vec[mid]} < \text{key} \), update \( \text{start} = \text{mid} + 1 = 6 \).

4. **Fourth Iteration:**
   - Start = 6, End = 6
   - Mid = \( \left\lfloor \frac{6 + 6}{2} \right\rfloor = 6 \)
   - vec[6] = 10 (not equal to 8).
   - Since \( \text{vec[mid]} > \text{key} \), update \( \text{end} = \text{mid} - 1 = 5 \).

5. **Termination:**
   - Start > End (6 > 5), so the key is not present. Return \( -1 \).

#### **Advantages:**
- **Time Complexity:**
  - **Best Case:** \( O(1) \) (when the key is at the middle).
  - **Worst Case:** \( O(\log n) \).
- **Space Complexity:** \( O(1) \).
- Efficient for large datasets when the list is sorted.

#### **Disadvantages:**
- Requires the input to be sorted.
- Inefficient for small datasets compared to simpler algorithms like linear search.
