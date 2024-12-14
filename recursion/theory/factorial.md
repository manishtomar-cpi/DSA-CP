## Factorial Function and Its Tree Representation

The factorial function can be defined as:

### Code Example

```cpp
#include <iostream>
using namespace std;

int fact(int n)
{
    // Base case
    if (n == 0)
    {
        return 1;
    }

    // Recursive case
    return n * fact(n - 1);
}

int main()
{
    int x = 3;
    cout << "Factorial of " << x << " is: " << fact(x) << endl;
    return 0;
}
```

---

### Execution of Factorial for `n = 3`

The recursion for `fact(3)` unfolds as follows:
- `fact(3) = 3 * fact(2)`
- `fact(2) = 2 * fact(1)`
- `fact(1) = 1 * fact(0)`
- `fact(0) = 1` (Base case)

After reaching the base case, the recursion starts returning values:
- `fact(1) = 1 * 1 = 1`
- `fact(2) = 2 * 1 = 2`
- `fact(3) = 3 * 2 = 6`

---

### Tree Representation of Factorial Function

Here’s the tree representation of the recursive calls for `fact(3)`:

**Calling Phase:**

```
          fact(3)
           /   \
          3     fact(2)
                 /   \
                2     fact(1)
                       /   \
                      1     fact(0)
                             |
                             1 (Base Case)
```

**Returning Phase:**

```
          fact(3)
         (3 * 2 = 6)
           /   \
          3     fact(2)
               (2 * 1 = 2)
                 /   \
                2     fact(1)
                     (1 * 1 = 1)
                       /   \
                      1     fact(0)
                             |
                             1 (Base Case)
```

---

### Step-by-Step Breakdown:

1. **Calling Phase:**
   - `fact(3)` calls `fact(2)`.
   - `fact(2)` calls `fact(1)`.
   - `fact(1)` calls `fact(0)`.
   - `fact(0)` returns `1` (Base Case).

2. **Returning Phase:**
   - `fact(1)` computes `1 * fact(0)` → `1 * 1 = 1`.
   - `fact(2)` computes `2 * fact(1)` → `2 * 1 = 2`.
   - `fact(3)` computes `3 * fact(2)` → `3 * 2 = 6`.

---

### Output

```
Factorial of 3 is: 6
```
