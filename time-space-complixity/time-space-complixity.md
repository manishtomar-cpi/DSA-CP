# Time and Space Complexity in Algorithms

## Introduction
Time complexity and space complexity are crucial factors in analyzing the efficiency of an algorithm. They measure the computational resources required for an algorithm to solve a given problem as a function of input size.

### Why Use Big-O Notation?
Big-O notation provides an abstract measure of the efficiency of an algorithm by describing how its performance scales with input size.

- **Time Complexity**: Amount of time taken by an algorithm.
- **Space Complexity**: Amount of memory used by an algorithm.

### Common Asymptotic Notations:
1. **O(1)**: Constant time/space.
2. **O(log n)**: Logarithmic time/space.
3. **O(n)**: Linear time/space.
4. **O(n log n)**: Linearithmic time/space.
5. **O(n^2)**: Quadratic time/space.
6. **O(2^n)**: Exponential time/space.

---

## Detailed Analysis with Recurrence Relations and Step-by-Step Explanations

### O(1) Complexity
#### Example: Swapping Two Variables
- **Time Complexity**: O(1)
  - Swapping takes constant time regardless of input size.
- **Space Complexity**: O(1)
  - No additional memory is used beyond the variables.

```cpp
int a = 5, b = 10;
std::swap(a, b);  // Constant time and space.
```

---

### O(log n) Complexity
#### Algorithm: Binary Search
Binary Search works by repeatedly dividing the search interval in half. 

**Steps:**
1. The array is divided into two halves (this step takes O(1) time).
2. A single recursive call is made on one of the halves, reducing the problem size to `n/2`.
3. The base case is when the size of the array becomes 1.

#### Building the Recurrence Relation:
1. At each step, the algorithm divides the array, taking O(1) time.
2. Recursively processes one half, leading to:
   - T(n) = T(n/2) + O(1)

#### Solving the Recurrence Relation:
- At each level, the problem size reduces by half:
| Step | Problem Size | Time Taken |
|------|--------------|------------|
| 1    | n            | O(1)       |
| 2    | n/2          | O(1)       |
| 3    | n/4          | O(1)       |
| ...  | ...          | ...        |

Number of steps = log n (to reduce size to 1).
- Total time: O(log n).

```cpp
int binarySearch(std::vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

---

### O(n) Complexity
#### Algorithm: Linear Search
Linear Search traverses the entire array and checks each element against the target.

**Steps:**
1. For each element, perform a comparison (O(1) per element).
2. Worst case: Compare all `n` elements.

#### Time Complexity:
- Total comparisons = O(n).

#### Space Complexity:
- No additional memory used: O(1).

```cpp
int linearSearch(std::vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}
```

---

### O(n log n) Complexity
#### Algorithm: Merge Sort
Merge Sort recursively splits the array into halves, sorts them, and merges the sorted halves.

**Steps:**
1. Divide: Split the array into two halves (log n levels).
2. Conquer: Merge takes O(n) time at each level.

#### Building the Recurrence Relation:
1. Splitting the array into two halves: O(1).
2. Two recursive calls on halves of size `n/2`.
3. Merging the two sorted halves: O(n).

- T(n) = 2T(n/2) + O(n)

#### Solving the Recurrence Relation:
| Level | Subproblems | Work per Subproblem | Total Work |
|-------|-------------|---------------------|------------|
| 1     | 1           | O(n)               | O(n)       |
| 2     | 2           | O(n/2)             | O(n)       |
| 3     | 4           | O(n/4)             | O(n)       |
| ...   | ...         | ...                | ...        |

Total work = log n levels × O(n) per level = O(n log n).

#### Space Complexity:
- Recursive stack: O(log n).
- Auxiliary arrays: O(n).

```cpp
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

---

### O(n^2) Complexity
#### Algorithm: Bubble Sort
Bubble Sort repeatedly compares and swaps adjacent elements to sort the array.

**Steps:**
1. Outer loop runs `n` times.
2. Inner loop compares `n - i` elements in the i-th pass.

#### Building the Recurrence Relation:
1. Total comparisons in the first pass: n.
2. Total comparisons in the second pass: n-1.
3. Recurrence:
   - T(n) = O(n) + T(n-1)

#### Solving the Recurrence Relation:
| Pass | Comparisons |
|------|-------------|
| 1    | n           |
| 2    | n-1         |
| 3    | n-2         |
| ...  | ...         |

Sum of series = n + (n-1) + (n-2) + ... + 1 = O(n^2).

#### Space Complexity:
- O(1) (in-place swaps).

```cpp
void bubbleSort(std::vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
        }
    }
}
```

---

### Recursive Algorithms
#### Recursive Binary Search
Binary Search using recursion follows the same principles as the iterative approach.

**Steps:**
1. Divide the array into halves (O(1)).
2. Recursively call on one half (T(n/2)).

#### Recurrence Relation:
- T(n) = T(n/2) + O(1)

#### Solution:
- Total levels: log n (reduce to size 1).
- Time: O(log n).

```cpp
int binarySearchRecursive(std::vector<int>& arr, int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, right, target);
        else return binarySearchRecursive(arr, left, mid - 1, target);
    }
    return -1;
}
```

---

## Conclusion
Understanding time and space complexities involves systematically analyzing each step of an algorithm. Recurrence relations and detailed step-by-step explanations provide a clear understanding of how algorithms behave with varying input sizes. Big-O notation allows us to generalize and compare these behaviors, aiding in the selection of efficient solutions for different problems.
