# Recursion

Recursion is a programming technique where a function calls itself to solve smaller instances of a problem until it reaches a stopping condition. It is a fundamental concept in computer science, widely used to simplify complex problems like traversing trees, solving mathematical computations, or implementing algorithms like sorting and searching.

---

## Key Concepts of Recursion

1. **Base Case**: The condition that stops the recursion. Without it, the function will continue indefinitely. 
2. **Recursive Case**: The function calls itself with a smaller or simpler input. 
3. **Depth-First Execution**: Recursion works in a "depth-first" manner, solving one branch completely before moving to the next.

---

## Example 1: Function `fun1`

### Code Example

```cpp
#include <iostream>
using namespace std;

void fun1(int n)
{
    if (n > 0)
    {
        cout << n << " ";
        fun1(n - 1);
    }
}

int main()
{
    int x = 3;
    fun1(x);
    return 0;
}
```

### Explanation

1. **Base Case**: If `n <= 0`, the recursion stops because the condition `n > 0` fails.
2. **Recursive Case**: If `n > 0`, the function prints the current value of `n` and calls itself with `n - 1`.

#### Execution Steps
- First Call: `fun1(3)` prints `3` and calls `fun1(2)`.
- Second Call: `fun1(2)` prints `2` and calls `fun1(1)`.
- Third Call: `fun1(1)` prints `1` and calls `fun1(0)`.
- Fourth Call: `fun1(0)` stops because `n <= 0`.

#### Recursion Tree Representation

```
          fun1(3)
          /    \
         3    fun1(2)
               /    \
              2    fun1(1)
                    /    \
                   1    fun1(0) -> stops
```

#### Output

```
3 2 1
```

---

## Example 2: Function `fun2`

### Code Example

```cpp
#include <iostream>
using namespace std;

void fun2(int n)
{
    if (n > 0)
    {
        fun2(n - 1);
        cout << n << " ";
    }
}

int main()
{
    int x = 3;
    fun2(x);
    return 0;
}
```

### Explanation

1. **Base Case**: If `n <= 0`, the recursion stops because the condition `n > 0` fails.
2. **Recursive Case**: If `n > 0`, the function calls itself with `n - 1`. After returning from the recursive call, it prints the value of `n`.

#### Execution Steps

### Step 1: Recursive Calls Only (No Printing Yet)

- First Call: `fun2(3)` calls `fun2(2)`.
- Second Call: `fun2(2)` calls `fun2(1)`.
- Third Call: `fun2(1)` calls `fun2(0)`.
- Fourth Call: `fun2(0)` stops because `n <= 0`.

#### Partial Tree for Recursive Calls

```
          fun2(3)
          /    \
     fun2(2)   (print later)
        /    \
   fun2(1)   (print later)
      /    \
 fun2(0)   (print later)
```

At this point, all recursive calls have been made, and the function starts returning.

### Step 2: Printing During Return Phase

- As the calls return:
  - `fun2(1)` prints `1`.
  - `fun2(2)` prints `2`.
  - `fun2(3)` prints `3`.

#### Full Tree with Print Execution

```
          fun2(3)
          /    \
     fun2(2)   3 <- Executes after returning from fun2(2)
        /    \
   fun2(1)   2 <- Executes after returning from fun2(1)
      /    \
 fun2(0)   1 <- Executes after returning from fun2(0)
```

#### Execution Flow

- Starts with `fun2(3)`.
- Goes down to `fun2(0)` (base case).
- Then goes back up, executing the print statements in reverse order: `1`, `2`, `3`.

#### Output

```
1 2 3
```

---

## Comparison of `fun1` and `fun2`

| Aspect               | `fun1`                           | `fun2`                           |
|----------------------|-----------------------------------|-----------------------------------|
| **Print Statement**  | Before the recursive call         | After the recursive call          |
| **Output**           | `3 2 1`                          | `1 2 3`                          |
| **Execution Order**  | Top-down                         | Bottom-up                        |

---

## Key Takeaways

1. The position of the print statement (before or after the recursive call) determines whether recursion works in a "top-down" or "bottom-up" manner.
2. In `fun1`, values are printed before making the recursive call, resulting in output from `n` to `1`.
3. In `fun2`, values are printed after returning from the recursive call, resulting in output from `1` to `n`.

