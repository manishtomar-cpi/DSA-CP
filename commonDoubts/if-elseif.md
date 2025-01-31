# When to Use `if`-`if`-`if` vs `if-else if`-`else`

### **When to use `if`-`if`-`if`?**

- Use it when **all conditions are checked**, even if one is true.
- Every `if` is **independent** of the others.

#### Example:
Imagine you are checking if a number is divisible by 2, 3, and 5. The number can be divisible by all of them at the same time.

```cpp
#include <iostream>
using namespace std;

int main() {
    int number = 30;

    if (number % 2 == 0) {
        cout << "Divisible by 2" << endl;
    }
    if (number % 3 == 0) {
        cout << "Divisible by 3" << endl;
    }
    if (number % 5 == 0) {
        cout << "Divisible by 5" << endl;
    }

    return 0;
}
```

**Output:**
```
Divisible by 2
Divisible by 3
Divisible by 5
```

Here, **all conditions are checked** because they don’t depend on each other.

---

### **When to use `if-else if`-`else`?**

- Use it when **only one condition** can be true.
- Once a condition is true, it stops checking the rest.

#### Example:
Imagine you are checking if a number is negative, zero, or positive. It can only be **one of these**.

```cpp
#include <iostream>
using namespace std;

int main() {
    int number = 10;

    if (number < 0) {
        cout << "Negative number" << endl;
    } else if (number == 0) {
        cout << "Zero" << endl;
    } else {
        cout << "Positive number" << endl;
    }

    return 0;
}
```

**Output:**
```
Positive number
```

Here, as soon as it finds the true condition, it **skips the rest**.

---

### **Key difference:**

- Use `if`-`if`-`if` if you want **all conditions to be checked**.
- Use `if-else if`-`else` if you want **only one condition** to be true.

---

### **Comparison Example:**
#### Multiple `if`:
```cpp
#include <iostream>
using namespace std;

int main() {
    int score = 85;

    if (score >= 50) {
        cout << "Passed" << endl;
    }
    if (score >= 80) {
        cout << "Distinction" << endl;
    }

    return 0;
}
```
**Output:**
```
Passed
Distinction
```
Both conditions are true, so both are checked.

#### `if-else if`:
```cpp
#include <iostream>
using namespace std;

int main() {
    int score = 85;

    if (score < 50) {
        cout << "Failed" << endl;
    } else if (score < 80) {
        cout << "Passed" << endl;
    } else {
        cout << "Distinction" << endl;
    }

    return 0;
}
```
**Output:**
```
Distinction
```
Here, only one condition is checked, and it stops after finding the correct one.

---

### **In short:**
- Use `if`-`if`-`if` when conditions are **independent**.
- Use `if-else if` when conditions are **mutually exclusive** (only one can be true).
