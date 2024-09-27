#include <iostream>
using namespace std;

int main()
{
    int a[10];

    a[0] = 2;
    a[4] = 9;

    cout << a[0] << endl; // 2
    cout << a[3] << endl; // garbage

    // initialisation
    int arr[4] = {1, 2, 3, 4};

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    //when garbage when 0
    int arr1[10];
     for (auto &i : arr1) //all garbage
    {
        cout << i << " ";
    }
    cout << endl;


     int arr2[10] ={1,4,6}; // 1,4,6,0,0.... -> because define some values
     for (auto &i : arr2) //all garbage
    {
        cout << i << " ";
    }
    cout << endl;


    // int arr[]; //give error have to define size

    int arr3[10];
    cout << sizeof(arr3)<< endl;

    return 0;
}

// Key Concepts in the Code:

// Array Declaration and Initialization:
// Arrays can be declared with or without initialization.
// Example: int a[10]; declares an array of size 10.
// Partial initialization like int arr2[10] = {1, 4, 6}; initializes the first few elements and sets the rest to 0.
// Uninitialized arrays contain garbage values (random data).

// Accessing Array Elements:
// Elements are accessed using indices, starting from 0.
// Example: a[0] = 2; assigns 2 to the first element of the array a.
// Accessing uninitialized indices returns garbage values.
// Example: cout << a[3]; outputs a garbage value.

// Range-based for Loop:
// Range-based for loops (C++11) allow easy iteration over arrays.
// Syntax: for (auto i : arr) iterates through each element.
// Example: for (auto i : arr) prints each element of arr.

// Using References in Range-based Loops:
// Using references (&) in a range-based loop allows direct modification or ensures no copy is made.
// Example: for (auto &i : arr1) iterates through arr1 and can modify its elements if needed.

// Array Size and Memory:
// sizeof(arr3) gives the total size of the array in bytes.
// For example, if arr3 is an array of 10 integers, and each integer is 4 bytes, the output would be 40 (bytes).

// Code Breakdown:
// Array declaration and assignment:
// a[10]: Array of size 10, elements can be accessed/modified.
// arr[4] = {1, 2, 3, 4}: Initializes all elements.
// arr2[10] = {1, 4, 6}: Partially initialized; rest of the elements are set to 0.

// Array access and garbage values:
// Uninitialized array elements contain garbage values.
// Arrays initialized with fewer elements have the remaining elements as 0.

// Range-based for loops:
// for (auto i : arr): Loop over the array and print values.
// for (auto &i : arr1): Reference loop used for arrays without initialization.

// Size of array:
// sizeof(arr3) gives the total size of the array in memory (in bytes).
