# Key Concepts in C++ Arrays

## Array Declaration and Initialization

Arrays in C++ can be declared and initialized in various ways:
- `int a[10];`: Declares an array `a` of size 10.
- `int arr2[10] = {1, 4, 6};`: Initializes the first three elements of `arr2` and sets the rest to 0.
- Uninitialized arrays contain garbage values (random data).

## Accessing Array Elements

Elements in arrays are accessed using indices starting from 0:
- Example: `a[0] = 2;` assigns 2 to the first element of array `a`.
- Accessing uninitialized indices returns garbage values.
  - Example: `cout << a[3];` outputs a garbage value.

## Range-based for Loop

Introduced in C++11, range-based for loops simplify iteration over arrays:
- Syntax: `for (auto i : arr)` iterates through each element `i` in array `arr`.
- Example: `for (auto i : arr)` prints each element of `arr`.

## Using References in Range-based Loops

Using references (`&`) in a range-based loop allows direct modification or avoids unnecessary copying:
- Example: `for (auto &i : arr1)` iterates through `arr1` and can modify its elements if needed.

## Array Size and Memory

`sizeof(arr3)` gives the total size of the array `arr3` in bytes:
- Example: If `arr3` is an array of 10 integers, and each integer occupies 4 bytes, `sizeof(arr3)` would output 40 bytes.

## Code Example

```cpp
#include <iostream>
using namespace std;

int main() {
    // Array declaration and assignment
    int a[10]; // Array of size 10
    int arr[4] = {1, 2, 3, 4}; // Initializes all elements
    int arr2[10] = {1, 4, 6}; // Partial initialization; rest of the elements are set to 0

    // Array access and garbage values
    // Uninitialized elements contain garbage values
    // Arrays initialized with fewer elements have the remaining elements as 0

    // Range-based for loops
    // for (auto i : arr): Loop over the array and print values
    // for (auto &i : arr1): Reference loop used for arrays without initialization

    // Size of array
    // sizeof(arr3) gives the total size of the array in memory (in bytes)

    return 0;
}
