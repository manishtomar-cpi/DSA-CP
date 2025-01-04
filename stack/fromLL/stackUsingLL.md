# Stack: Implementation Using Linked List

## Why Use a Linked List for a Stack?

Unlike an array-based stack, a linked list-based stack has the following advantages:
1. **Dynamic Size:** No fixed capacity; memory is allocated dynamically.
2. **Efficient Memory Usage:** No wasted space, as memory is allocated only when required.
3. **No Overflow (in most cases):** Overflow occurs only if the system runs out of heap memory.

---

## How a Linked List Implements a Stack

A **linked list** consists of nodes where each node contains:
1. **Data:** The value stored in the node.
2. **Next Pointer:** A reference to the next node in the list.

### Stack Operations Using a Linked List

1. **Push:**
   - Create a new node with the given value.
   - Point the new node’s `next` pointer to the current `top`.
   - Update `top` to point to the new node.

2. **Pop:**
   - Check if the stack is empty.
   - If not, store the current `top` in a temporary pointer.
   - Update `top` to point to `top->next`.
   - Delete the temporary node to free memory.

3. **Peek:**
   - Return the value of the node at `top` without modifying the stack.

4. **isEmpty:**
   - Check if `top` is `nullptr`.

5. **isFull:**
   - Try to allocate a new node.
   - If allocation fails, the stack is full.

---

## How the Stack is Built

### **Step-by-Step Explanation**

1. **Initialization:**
   - The stack starts with `top = nullptr`, meaning it is empty.
   - There is no node, so there is no data to work with.

   ```
   Stack (empty):
   top -> nullptr
   ```

2. **Push Operation: Adding Elements**
   - **Step 1:** Create a new node.
   - **Step 2:** Link the new node’s `next` pointer to the current `top`.
   - **Step 3:** Update the `top` pointer to point to the new node.

   Example: Push `10`, `20`, and `30` in that order.

   #### Push `10`:
   - Create a new node with `data = 10` and `next = nullptr`.
   - Set `top = newNode`.

   ```
   Stack:
   top -> [10] -> nullptr
   ```

   #### Push `20`:
   - Create a new node with `data = 20`.
   - Link `newNode->next` to the current `top` (which is `[10]`).
   - Update `top = newNode`.

   ```
   Stack:
   top -> [20] -> [10] -> nullptr
   ```

   #### Push `30`:
   - Create a new node with `data = 30`.
   - Link `newNode->next` to the current `top` (which is `[20]`).
   - Update `top = newNode`.

   ```
   Stack:
   top -> [30] -> [20] -> [10] -> nullptr
   ```

3. **Pop Operation: Removing Elements**
   - **Step 1:** Check if the stack is empty (`top == nullptr`). If it is, return an error (stack underflow).
   - **Step 2:** Save the current `top` node in a temporary pointer.
   - **Step 3:** Update `top` to `top->next` (effectively skipping the current top node).
   - **Step 4:** Delete the temporary pointer to free memory.

   Example: Pop from the stack.

   #### Pop:
   - The current `top` is `[30]`.
   - Update `top = top->next` (which is `[20]`).
   - Free the memory of `[30]`.

   ```
   Stack:
   top -> [20] -> [10] -> nullptr
   ```

   #### Another Pop:
   - The current `top` is `[20]`.
   - Update `top = top->next` (which is `[10]`).
   - Free the memory of `[20]`.

   ```
   Stack:
   top -> [10] -> nullptr
   ```

   #### Another Pop:
   - The current `top` is `[10]`.
   - Update `top = top->next` (which is `nullptr`).
   - Free the memory of `[10]`.

   ```
   Stack (empty):
   top -> nullptr
   ```

---

## C++ Implementation of Stack Using Linked List

```cpp
#include <iostream>
using namespace std;

// Node class represents a single element in the stack
class Node {
public:
    int data;       // Data of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a new node
    Node(int val) : data(val), next(nullptr) {}
};

// Stack class implements the stack using a linked list
class Stack {
private:
    Node* top = nullptr; // Pointer to the top node of the stack

public:
    // Push operation: Adds a new value to the stack
    void push(int val) {
        Node* temp = new Node(val);
        if (temp == nullptr) {
            cout << "Cannot push: Stack overflow!" << endl;
        } else {
            temp->next = top; // Link new node to the current top
            top = temp;       // Update top to the new node
            cout << "Pushed: " << val << endl;
        }
    }

    // Pop operation: Removes the top value from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow: Stack is empty!" << endl;
        } else {
            Node* temp = top;
            top = top->next; // Update top to the next node
            cout << "Popped: " << temp->data << "!" << endl;
            delete temp;     // Free memory of the old top node
        }
    }

    // Peek operation: Returns the top value without removing it
    int peek() {
        if (top == nullptr) {
            cout << "Stack empty!" << endl;
            return -1; // Return -1 as a signal of an empty stack
        } else {
            return top->data;
        }
    }

    // Access element at a specific index (1-based)
    int atIndex(int index) {
        Node* temp = top;
        for (int i = 1; temp != nullptr && i < index; i++) {
            temp = temp->next; // Move to the next node
        }

        if (temp != nullptr) { // Valid index
            return temp->data;
        } else {
            cout << "Invalid position!" << endl;
            return -1; // Indicate an invalid position
        }
    }

    // Check if the stack is full (depends on memory availability)
    bool isFull() {
        // Try to allocate a temporary node
        Node* temp = new (nothrow) Node(-1);
        if (temp == nullptr) { // Allocation failed
            return true;
        } else {
            delete temp; // Free the temporary node
            return false; // Memory is available
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr; // If top is null, the stack is empty
    }
};

int main() {
    Stack s1;

    // Demonstrating stack operations
    s1.push(10);                                     // [10]
    cout << "Top element is: " << s1.peek() << endl; // 10
    s1.push(20);                                     // [20, 10]
    s1.push(30);                                     // [30, 20, 10]
    s1.push(40);                                     // [40, 30, 20, 10]
    cout << "Top element is: " << s1.peek() << endl; // 40
    s1.pop();                                        // [30, 20, 10]
    cout << "Top element is: " << s1.peek() << endl; // 30
    s1.pop();                                        // [20, 10]
    s1.pop();                                        // [10]
    cout << "Top element is: " << s1.peek() << endl; // 10
    s1.pop();                                        // []
    cout << "Top element is: " << s1.peek() << endl; // -1 (invalid)

    // Testing isEmpty
    cout << boolalpha;
    cout << "Is stack empty? " << s1.isEmpty() << endl; // true
    s1.push(10);                                        // [10]
    cout << "Is stack empty? " << s1.isEmpty() << endl; // false

    // Testing atIndex
    s1.push(20);                   // [20, 10]
    s1.push(30);                   // [30, 20, 10]
    cout << "Element at index 2: " << s1.atIndex(2) << endl; // 20
    cout << "Element at index 4: " << s1.atIndex(4) << endl; // -1 (invalid)

    // Testing isFull
    cout << "Is stack full? " << s1.isFull() << endl; // false (depends on memory availability)

    return 0;
}
```

---

## Advantages of Linked List-Based Stack

1. **Dynamic Memory:** Automatically adjusts size as elements are pushed or popped.
2. **No Size Limit:** Limited only by available system memory.
3. **Efficient Push/Pop:** Both operations are O(1).

## Disadvantages of Linked List-Based Stack

1. **Memory Overhead:** Each node requires extra memory for the `next` pointer.
2. **Complexity:** Slightly more complex than array-based implementation.

---

## Notes for Best Practices

1. Always check for memory allocation failures.
2. Free memory for nodes during `pop` to avoid memory leaks.
3. Encapsulate stack operations to maintain proper abstraction.

---