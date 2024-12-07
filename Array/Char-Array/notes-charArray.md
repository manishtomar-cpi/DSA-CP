

```markdown
# C String Functions in C++

## 1. `strlen`

- **Purpose:** Calculates the length of a C-style string (number of characters before the null terminator).
- **Syntax:** `size_t strlen(const char* str);`
- **Example:**
  ```cpp
  #include <cstring>
  const char* name = "Hello";
  size_t length = strlen(name);  // length will be 5
  ```

## 2. `strcmp`

- **Purpose:** Compares two C-style strings.
- **Syntax:** `int strcmp(const char* str1, const char* str2);`
- **How it Works:**
  - Compares characters in both strings one by one.
  - Returns:
    - 0 if both strings are equal.
    - A negative value if `str1` is less than `str2`.
    - A positive value if `str1` is greater than `str2`.
- **Example:**
  ```cpp
  #include <cstring>
  const char* str1 = "apple";
  const char* str2 = "banana";
  int result = strcmp(str1, str2);  // result is negative because "apple" < "banana"
  ```

## 3. `strcpy`

- **Purpose:** Copies one C-style string to another.
- **Syntax:** `char* strcpy(char* dest, const char* src);`
- **What it Does:** Copies the entire `src` string, including the null terminator, into `dest`.
- **Example:**
  ```cpp
  #include <cstring>
  char source[] = "Hello";
  char destination[10];  // Make sure it's large enough
  strcpy(destination, source);  // destination now holds "Hello"
  ```

## 4. `strncpy`

- **Purpose:** Copies a specified number of characters from one string to another.
- **Syntax:** `char* strncpy(char* dest, const char* src, size_t n);`
- **Key Difference from `strcpy`:**
  - Does not guarantee null termination if `n` is less than the length of `src`.
  - If `src` has fewer characters than `n`, fills the remaining characters in `dest` with nulls.
- **Example:**
  ```cpp
  #include <cstring>
  char source[] = "Hello";
  char destination[10];
  strncpy(destination, source, 3);  // destination now holds "Hel"
  destination[3] = '\0';  // Manually add null terminator if needed
  ```

## 5. `strcat`

- **Purpose:** Concatenates (appends) one string to another.
- **Syntax:** `char* strcat(char* dest, const char* src);`
- **What it Does:** Adds the `src` string to the end of `dest`, overwriting the null terminator of `dest`.
- **Example:**
  ```cpp
  #include <cstring>
  char destination[20] = "Hello";
  const char* source = " World";
  strcat(destination, source);  // destination now holds "Hello World"
  ```

---

## Summary

- **`strlen`:** Get the length of a string.
- **`strcmp`:** Compare two strings for equality or order.
- **`strcpy`:** Copy one string to another (includes null terminator).
- **`strncpy`:** Copy a specified number of characters from one string to another (may not include null).
- **`strcat`:** Append one string to another.

These functions are essential for handling C-style strings in C++ programming. Always ensure your destination arrays are large enough to hold the strings you are working with to avoid buffer overflows.
```

