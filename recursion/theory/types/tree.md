# Types of Recursion: Tree Recursion

Tree recursion occurs when a function makes more than one recursive call within its definition. This leads to a branching structure resembling a tree. Tree recursion is useful in scenarios where problems are naturally divided into multiple sub-problems, such as generating combinations, solving Fibonacci sequences, or traversing hierarchical structures.

---

## Code Example: Tree Recursion

### Function Definition

```cpp
#include <iostream>
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);              // 1. Recursive call (left branch)
        cout << n << " ";       // 2. Print current value
        fun(n - 1);              // 3. Recursive call (right branch)
    }
}

int main()
{
    fun(3);
    return 0;
}
```

---

## Explanation

### Execution Flow:
1. The function `fun(3)` starts with `n = 3`.
2. It first recursively calls `fun(2)` (left branch).
3. The left branch (`fun(2)`) recursively calls `fun(1)` and completes its left and right branches.
4. The `fun(3)` function then prints `3` after its left subtree completes.
5. Finally, the right branch of `fun(3)` is executed, repeating the same process as the left.

---

## Step-by-Step Tree Expansion for `fun(3)`

### Step 1: Start with `fun(3)`
```
fun(3)
```

### Step 2: Expand the left branch of `fun(3)`
```
          fun(3)
         /     \
    fun(2)
```

### Step 3: Expand the left branch of `fun(2)`
```
          fun(3)
         /     \
    fun(2)
   /     \
fun(1)
```

### Step 4: Expand the left branch of `fun(1)`
```
          fun(3)
         /     \
    fun(2)
   /     \
fun(1)
  /
fun(0)
```

### Step 5: Expand the right branch of `fun(1)` after the left branch completes
```
          fun(3)
         /     \
    fun(2)
   /     \
fun(1)
  /     \
fun(0) fun(0)
```

### Step 6: Complete the right branch of `fun(2)`
```
          fun(3)
         /     \
    fun(2)
   /     \
fun(1)  fun(1)
  / \     / \
fun(0) fun(0) fun(0) fun(0)
```

### Step 7: Complete the right branch of `fun(3)`
```
          fun(3)
         /     \
    fun(2)      fun(2)
   /     \      /     \
fun(1)  fun(1) fun(1)  fun(1)
  / \     / \     / \     / \
fun(0) fun(0) fun(0) fun(0) fun(0) fun(0) fun(0) fun(0)
```

---

## Activation Record Stack (Call Stack Representation)

The activation record stack shows how recursive calls are stored in the stack memory during execution. For `fun(3)`, the stack evolves as follows:

### Calling Phase (Stack Push):
1. Call `fun(3)` → Push `fun(3)` to stack.
2. Call `fun(2)` → Push `fun(2)` to stack.
3. Call `fun(1)` → Push `fun(1)` to stack.
4. Call `fun(0)` → Push `fun(0)` to stack (base case).

### Returning Phase (Stack Pop):
1. `fun(0)` completes and is popped from the stack.
2. Return to `fun(1)`, execute its right branch, and pop after completion.
3. Continue this process until all recursive calls complete.

### Visual Representation of the Stack:

```
+------------------+
| fun(0)          |
| fun(1)          |
| fun(2)          |
| fun(3)          |
+------------------+
```

As each branch completes, the corresponding function is popped off the stack.

---

## Output for `fun(3)`:

```
1 1 2 1 1 3 1 1 2 1 1
```

---

## Key Takeaways:
1. **Tree recursion leads to exponential growth in the number of function calls.** For `n`, the number of calls is approximately `2^n - 1`.
2. **Understanding the call stack** is essential for visualizing how tree recursion works and why it consumes more memory compared to linear recursion.
3. **Base cases are critical** to ensure recursion terminates and avoids infinite loops.

