# Queue

## Overview

A queue is a linear data structure that follows the First In, First Out (FIFO) principle, where elements are added at one end, called the rear, and removed from the other end, called the front. This C++ implementation uses a static array to demonstrate basic queue operations including enqueue (adding elements), dequeue (removing elements), and displaying the queue contents.

## Code Structure

The `Queue` class is defined with private members for the capacity, front and rear indices, and a pointer to a dynamically allocated array that holds the queue elements. Public methods include constructors, destructors, and methods to handle enqueue, dequeue, and display operations.

### Key Methods

- `enqueue(int val)`: Adds an element at the rear of the queue. If the queue is full, it prints an error message.
- `dequeue()`: Removes the element from the front of the queue. If the queue is empty, it prints an error message.
- `display()`: Prints out the elements of the queue from front to rear, marking the front and rear elements distinctly, and shows empty slots in the queue.

## Limitations of Array-Based Implementation

Using a static array to implement a queue introduces several limitations:

### Fixed Capacity

- The size of the queue is fixed upon creation and cannot be dynamically adjusted at runtime. This can lead to either wasted space if the array is too large, or inability to add elements if the array is too small and full.

### Inefficient Space Utilization

- Once elements are dequeued from the front, their positions in the array remain unused. Even though there may be free space at the front of the array, new elements can only be added if there is space at the rear. This leads to suboptimal use of allocated space.

### Potential for Data Overwrites

- If not carefully managed, especially in a non-circular array implementation, adding elements to a full queue can overwrite existing elements or cause array index out-of-bound errors.

## Conclusion

While the array-based queue is simple and provides an easy-to-understand example of the FIFO concept, its practical use is limited due to its fixed size and inefficient use of space. For applications requiring dynamic and efficient queue operations, a linked list or circular array implementation is recommended.

