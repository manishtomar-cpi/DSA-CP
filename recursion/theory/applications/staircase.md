# Staircase Problem: Number of Ways to Reach the Top

## Problem Statement
You are standing at the bottom of a staircase with `N` steps. You can take a jump of 1, 2, or 3 steps at a time. Find the total number of distinct ways to reach the top.

### Examples:
1. For `N = 3`, the possible ways are:
   - `1, 1, 1`
   - `1, 2`
   - `2, 1`
   - `3`
   
   **Total Ways = 4**

2. For `N = 4`, the possible ways are:
   - `1, 1, 1, 1`
   - `1, 1, 2`
   - `1, 2, 1`
   - `2, 1, 1`
   - `1, 3`
   - `3, 1`
   - `2, 2`

   **Total Ways = 7**

---

## Approach

The problem can be solved using **recursion** with the following recursive formula:

### Recursive Formula:
For `f(N)` (number of ways to reach step `N`):
```
f(N) = f(N-1) + f(N-2) + f(N-3)
```
- `f(N-1)`: Represents taking a single-step jump to `N`.
- `f(N-2)`: Represents taking a two-step jump to `N`.
- `f(N-3)`: Represents taking a three-step jump to `N`.

### Base Cases:
1. `f(0) = 1`: There's only one way to stay at the bottom.
2. `f(1) = 1`: One way to reach the first step (a single jump).
3. `f(2) = 2`: Two ways to reach the second step (`1+1` or `2`).

---

## Solution Using Recursion

### Recursive Implementation:
```cpp
#include <iostream>
using namespace std;

int countWays(int n) {
    if (n == 0) return 1; // Base case: 1 way to stay at step 0
    if (n < 0) return 0;  // Base case: No way to go negative steps

    // Recursive relation
    return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int main() {
    int n = 4; // Number of steps
    cout << "Number of ways to reach step " << n << ": " << countWays(n) << endl;
    return 0;
}
```

### Output for `N = 4`:
```
Number of ways to reach step 4: 7
```

---

## Solution Using Dynamic Programming (DP)

### Why Use DP?
Recursion can lead to redundant calculations for overlapping subproblems. By storing the results of subproblems (memoization) or solving iteratively (tabulation), we can improve efficiency.

### DP Formula:
```
ways[0] = 1
ways[1] = 1
ways[2] = 2
ways[i] = ways[i-1] + ways[i-2] + ways[i-3] for i >= 3
```

### DP Implementation:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int countWaysDP(int n) {
    vector<int> ways(n + 1, 0);

    // Base cases
    ways[0] = 1;
    if (n >= 1) ways[1] = 1;
    if (n >= 2) ways[2] = 2;

    // Fill DP table
    for (int i = 3; i <= n; i++) {
        ways[i] = ways[i - 1] + ways[i - 2] + ways[i - 3];
    }

    return ways[n];
}

int main() {
    int n = 4; // Number of steps
    cout << "Number of ways to reach step " << n << ": " << countWaysDP(n) << endl;
    return 0;
}
```

### Output for `N = 4`:
```
Number of ways to reach step 4: 7
```

---

## Example Walkthrough for `N = 4`

### Recursive Tree:
```
                             f(4)
                     /        |        \
                 f(3)       f(2)      f(1)
              /   |   \     /   \       |
          f(2) f(1) f(0) f(1) f(0)    f(0)
          / | \   |     |   |
      f(1) f(0) f(-1) ...
```
- **Base cases stop recursion** when `N == 0` or `N < 0`.
- The result combines results from all branches.

### Dynamic Programming Table for `N = 4`:
| Step | `ways[i]` | Explanation                   |
|------|-----------|-------------------------------|
| 0    | 1         | 1 way to stay at the bottom   |
| 1    | 1         | Only one way: single jump     |
| 2    | 2         | `1+1` or `2`                 |
| 3    | 4         | `1+1+1`, `1+2`, `2+1`, `3`   |
| 4    | 7         | Combine all valid paths      |

---

## Complexity Analysis

### Recursive Solution:
- **Time Complexity**: `O(3^N)` (Exponential due to the branching factor of 3).
- **Space Complexity**: `O(N)` (Recursive call stack).

### Dynamic Programming Solution:
- **Time Complexity**: `O(N)` (Single loop).
- **Space Complexity**: `O(N)` (DP table). Can be optimized to `O(1)` by storing only the last three values.

---

## Additional Example

### Example for `N = 5`:
- Ways:
  - `1, 1, 1, 1, 1`
  - `1, 1, 1, 2`
  - `1, 1, 2, 1`
  - `1, 2, 1, 1`
  - `2, 1, 1, 1`
  - `1, 2, 2`
  - `2, 1, 2`
  - `2, 2, 1`
  - `1, 1, 3`
  - `1, 3, 1`
  - `3, 1, 1`
  - `2, 3`
  - `3, 2`

**Total Ways = 13**
