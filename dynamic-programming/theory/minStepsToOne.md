# Minimum Steps to 1 Problem

## Problem Statement
Given a number `n`, find the minimum number of steps required to reduce it to `1` using the following operations:
- If `n` is divisible by `3`, you can divide `n` by `3`.
- If `n` is divisible by `2`, you can divide `n` by `2`.
- You can subtract `1` from `n`.

The goal is to find the optimal way to reach `1` in the fewest steps.

---

## Approach 1: Greedy Approach (Incorrect in Some Cases)
### Implementation: `_Minimum_Steps_To_1_`
```cpp
int _Minimum_Steps_To_1_(int n) {
    if (n <= 0) {
        return -1;
    }
    int steps = 0;
    while (n != 1) {
        if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n -= 1;
        }
        steps++;
    }
    return steps;
}
```
#### Explanation
- The function greedily selects division by `3` if possible, then division by `2`, otherwise subtracts `1`.
- **Issue**: This approach does not always find the minimum steps.
  - Example: `_Minimum_Steps_To_1_(10)` follows `10 → 5 → 4 → 2 → 1` (4 steps), whereas the optimal path is `10 → 9 → 3 → 1` (3 steps).

---

## Approach 2: Recursion (Exponential Time Complexity)
### Implementation: `minStepsUsingRec`
```cpp
int minStepsUsingRec(int n) {
    if (n <= 1) {
        return 0;
    }
    int first = minStepsUsingRec(n - 1);
    int second = INT8_MAX, third = INT8_MAX;
    if (n % 3 == 0) {
        second = minStepsUsingRec(n / 3);
    }
    if (n % 2 == 0) {
        third = minStepsUsingRec(n / 2);
    }
    return min(first, min(second, third)) + 1;
}
```
#### Explanation
- Computes results for all three possible operations recursively and takes the minimum.
- **Time Complexity**: `O(2^n)` (exponential) due to repeated calculations.
- **Issue**: Inefficient for large `n` due to repeated computations.

---

## Approach 3: Memoization (Top-Down Dynamic Programming)
### Implementation: `minStepUsing__DP`
```cpp
int minStepUsing__DP(int n, vector<int> &vec) {
    if (n <= 1) {
        return 0;
    }
    if (vec[n] != -1) {
        return vec[n];
    }
    int first = minStepUsing__DP(n - 1, vec);
    int second = INT16_MAX;
    int third = INT16_MAX;
    if (n % 3 == 0) {
        second = minStepUsing__DP(n / 3, vec);
    }
    if (n % 2 == 0) {
        third = minStepUsing__DP(n / 2, vec);
    }
    vec[n] = min(first, min(second, third)) + 1;
    return vec[n];
}
```
#### Explanation
- Uses a vector (`vec`) to store computed results, avoiding redundant calculations.
- **Time Complexity**: `O(n)`.
- **Space Complexity**: `O(n)` due to recursion stack.

---

## Approach 4: Iterative Dynamic Programming (Bottom-Up Approach)
### Implementation: `minStepsDP_Iterative`
```cpp
int minStepsDP_Iterative(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        int first = dp[i - 1];
        int second = INT8_MAX;
        int third = INT8_MAX;
        if (i % 2 == 0) {
            second = dp[i / 2];
        }
        if (i % 3 == 0) {
            third = dp[i / 3];
        }
        dp[i] = min(first, min(second, third)) + 1;
    }
    return dp[n];
}
```
#### Explanation
- Builds the solution iteratively from `1` to `n`, avoiding recursion.
- **Time Complexity**: `O(n)`.
- **Space Complexity**: `O(n)` (can be optimized to `O(1)`).

---

## Comparison of Approaches
| Approach | Time Complexity | Space Complexity | Efficiency |
|----------|---------------|----------------|------------|
| Greedy (Incorrect) | `O(n)` | `O(1)` | Fails for some cases |
| Recursion | `O(2^n)` | `O(n)` (recursion stack) | Inefficient |
| Memoization (Top-Down DP) | `O(n)` | `O(n)` | Good |
| Iterative DP (Bottom-Up) | `O(n)` | `O(n)` (can be optimized to `O(1)`) | Best |

---

## Conclusion
- The greedy approach is incorrect in some cases.
- The recursive approach works but is inefficient for large `n`.
- **Memoization (Top-Down DP)** improves efficiency but still uses extra space.
- **Iterative DP (Bottom-Up)** is the best approach, solving the problem efficiently with `O(n)` time.

---

## Sample Usage
```cpp
int main() {
    cout << minStepsDP_Iterative(10) << endl;  // Output: 3
    return 0;
}
