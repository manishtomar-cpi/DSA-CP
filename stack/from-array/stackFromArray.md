# Stack

## What is a Stack?

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle:
- The last element added to the stack is the first one to be removed.
- Think of a stack of plates: you add plates to the top, and you remove plates from the top.

## Key Operations

1. **Push:** Add an element to the top of the stack.
2. **Pop:** Remove the top element from the stack.
3. **Peek/Top:** Retrieve the top element without removing it.
4. **isEmpty:** Check if the stack is empty.
5. **isFull (optional):** Check if the stack is full (for fixed-size stacks).

## Applications of Stacks

- Expression evaluation (e.g., postfix or prefix notation)
- Undo operations in text editors
- Backtracking (e.g., maze solving, recursion)
- Memory management (function call stack)

---

## Stack Implementation Using Arrays

### Array as a Stack
- An **array** provides a fixed block of memory.
- By controlling the **top index**, we can treat an array like a stack.

### How it Works

1. **Initialization:**
   - Use an integer `top` to keep track of the topmost element. Initially, `top = -1`.

2. **Push Operation:**
   - Check if the stack is full (`top >= size - 1`).
   - Increment `top` and place the new element at `arr[top]`.

3. **Pop Operation:**
   - Check if the stack is empty (`top == -1`).
   - Retrieve the element at `arr[top]` and decrement `top`.

4. **Peek Operation:**
   - Return the element at `arr[top]` without modifying `top`.

---

## C++ Implementation

```cpp
#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;      // Pointer to hold the array
    int capacity;  // Maximum size of the stack
    int top;       // Index of the top element

public:
    // Constructor to initialize the stack
    Stack(int size) : capacity(size), top(-1) {
        arr = new int[capacity]; // Dynamically allocate array
    }

    // Destructor to free the allocated memory
    ~Stack() {
        delete[] arr;
        cout << "Stack memory released." << endl;
    }

    // Method to push an element onto the stack
    void push(int value) {
        if (top >= capacity - 1) {
            cout << "Stack Overflow: Cannot push " << value << endl;
        } else {
            arr[++top] = value; // Increment top and add value
            cout << "Pushed " << value << " onto the stack." << endl;
        }
    }

    // Method to pop the top element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow: No elements to pop." << endl;
        } else {
            cout << "Popped " << arr[top--] << " from the stack." << endl;
        }
    }

    // Method to peek at the top element without removing it
    int peek() {
        if (top < 0) {
            cout << "Stack is empty: No top element." << endl;
            return -1; // Return an invalid value to indicate an empty stack
        } else {
            return arr[top];
        }
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack stack(5); // Create stack with size 5

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    cout << "Top element after pop is: " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop(); // Trying to pop from an empty stack

    return 0;
}
```

---

## How the Array Acts as a Stack

- **Storage:** The array (`arr`) holds the stack elements.
- **Top Pointer:** The `top` index determines the "active" part of the array that represents the stack.
- **Operations:** By manipulating `top`, we control where elements are added or removed, simulating the stack's LIFO behavior.

### Visualization

1. **Initial State:**
   - `arr = [ ] [ ] [ ] [ ] [ ]`
   - `top = -1`

2. **Push Operations:**
   - `push(10)` → `arr = [10] [ ] [ ] [ ] [ ]`, `top = 0`
   - `push(20)` → `arr = [10] [20] [ ] [ ] [ ]`, `top = 1`
   - `push(30)` → `arr = [10] [20] [30] [ ] [ ]`, `top = 2`

3. **Pop Operations:**
   - `pop()` → Removes `30`, `arr = [10] [20] [ ] [ ] [ ]`, `top = 1`
   - `pop()` → Removes `20`, `arr = [10] [ ] [ ] [ ] [ ]`, `top = 0`

---

## Advantages of Using Arrays for Stacks

1. Simple and fast (O(1) for `push` and `pop` operations).
2. Efficient memory usage for fixed-size stacks.

## Limitations

1. Fixed size can lead to stack overflow or wasted memory.
2. Resizing the array requires extra work and may not be efficient.

---

## Notes for Best Practices

- Always check for **overflow** and **underflow** conditions.
- Use dynamic memory allocation for flexible stack sizes.
- Encapsulate the array and operations within a class to ensure safe usage.

---

