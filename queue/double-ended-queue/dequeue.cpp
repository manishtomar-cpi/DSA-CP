# Deque Implementation with Doubly Linked List

This document provides a detailed explanation of the implementation of a **Deque** (Double-Ended Queue) using a doubly linked list. The code supports enqueueing and dequeueing operations from both ends, along with utility functions to check the size, front, and rear elements.

## What is a Deque?
A **deque** (pronounced "deck") is a linear data structure that allows insertion and deletion of elements from both ends (front and rear). It is a generalized version of both stacks and queues, providing the following operations:

### Key Features:
1. **Bidirectional Operations**:
   - Insert and delete from both the front and rear.

2. **Dynamic Behavior**:
   - Can grow or shrink dynamically as needed.

3. **Use Cases**:
   - Sliding window problems.
   - Palindrome checking.
   - Task scheduling.

---

## Code Overview
The deque is implemented using a doubly linked list to support efficient insertions and deletions from both ends.

### **Key Components**
1. **Node Class**:
   - Represents a single element in the deque.
   - Each node stores:
     - `data`: The value of the node.
     - `next`: Pointer to the next node.
     - `prev`: Pointer to the previous node.

2. **Deque Class**:
   - Manages the nodes and provides the following functionalities:
     - `enqueueAtFront`: Adds an element to the front of the deque.
     - `enqueueAtRear`: Adds an element to the rear of the deque.
     - `dequeueAtFront`: Removes an element from the front of the deque.
     - `dequeueAtRear`: Removes an element from the rear of the deque.
     - `getFront`: Retrieves the value of the front element.
     - `getRear`: Retrieves the value of the rear element.
     - `isEmpty`: Checks if the deque is empty.
     - `size`: Returns the number of elements in the deque.

---

## Functionalities Explained
### **Enqueue at Front**
Adds an element to the front of the deque.
- If the deque is empty, the new node becomes both the `front` and `rear`.
- Otherwise, the new node is linked to the current front, and the `front` pointer is updated.

#### Diagram:
1. Before enqueueing `30` at the front:
```
10 <-> 20
```
2. After enqueueing `30`:
```
30 <-> 10 <-> 20
```

#### Code Snippet:
```cpp
void enqueueAtFront(int val)
{
    Node *temp = new Node(val);
    if (front == nullptr)
    {
        front = rear = temp;
    }
    else
    {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}
```

---

### **Enqueue at Rear**
Adds an element to the rear of the deque.
- If the deque is empty, the new node becomes both the `front` and `rear`.
- Otherwise, the new node is linked to the current rear, and the `rear` pointer is updated.

#### Diagram:
1. Before enqueueing `40` at the rear:
```
30 <-> 10 <-> 20
```
2. After enqueueing `40`:
```
30 <-> 10 <-> 20 <-> 40
```

#### Code Snippet:
```cpp
void enqueueAtRear(int val)
{
    Node *temp = new Node(val);
    if (front == nullptr)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
}
```

---

### **Dequeue at Front**
Removes an element from the front of the deque.
- If the deque is empty, a message is displayed.
- Otherwise, the `front` pointer is updated to the next node. If this was the last node, both `front` and `rear` are set to `nullptr`.

#### Diagram:
1. Before dequeueing from the front:
```
30 <-> 10 <-> 20 <-> 40
```
2. After dequeueing:
```
10 <-> 20 <-> 40
```

#### Code Snippet:
```cpp
void dequeueAtFront()
{
    if (front == nullptr)
    {
        cout << "queue empty!" << endl;
    }
    else
    {
        front = front->next;
        if (!front)
        {
            rear = nullptr;
        }
        else
        {
            front->prev = nullptr;
        }
    }
}
```

---

### **Dequeue at Rear**
Removes an element from the rear of the deque.
- If the deque is empty, a message is displayed.
- Otherwise, the `rear` pointer is updated to the previous node. If this was the last node, both `front` and `rear` are set to `nullptr`.

#### Diagram:
1. Before dequeueing from the rear:
```
10 <-> 20 <-> 40
```
2. After dequeueing:
```
10 <-> 20
```

#### Code Snippet:
```cpp
void dequeueAtRear()
{
    if (front == nullptr)
    {
        cout << "queue empty!" << endl;
    }
    else
    {
        rear = rear->prev;
        if (!rear)
        {
            front = nullptr;
        }
        else
        {
            rear->next = nullptr;
        }
    }
}
```

---

### **Utility Functions**
#### **Get Front**
Returns the value of the front element.
```cpp
int getFront()
{
    return (!front) ? -1 : front->data;
}
```

#### **Get Rear**
Returns the value of the rear element.
```cpp
int getRear()
{
    return (!rear) ? -1 : rear->data;
}
```

#### **Is Empty**
Checks if the deque is empty.
```cpp
bool isEmpty()
{
    return (front == nullptr);
}
```

#### **Size**
Returns the number of elements in the deque.
```cpp
int size()
{
    Node *temp = front;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
```

---

## Example Execution
### Input Code:
```cpp
int main()
{
    Deque q1;
    cout << boolalpha;
    cout << q1.isEmpty() << endl;  // T
    q1.enqueueAtFront(10);         // 10
    q1.enqueueAtRear(20);          // 10, 20
    cout << q1.getFront() << endl; // 10
    cout << q1.getRear() << endl;  // 20
    q1.enqueueAtFront(30);         // 30,10,20
    cout << q1.size() << endl;     // 3
    q1.dequeueAtFront();           // 10,20
    q1.dequeueAtRear();            // 10
    q1.dequeueAtRear();            // empty
    cout << q1.size() << endl;     // 0
    return 0;
}
```

### Output:
```
true
10 enqueued at front!
20 enqueued!
10
20
30 enqueued at front!
3
dequeued at front!
dequeued from rear!
dequeued from rear!
0
```

---

## Summary Table
| Function            | Description                                    | Complexity |
|---------------------|------------------------------------------------|------------|
| `enqueueAtFront`    | Adds an element to the front                  | O(1)       |
| `enqueueAtRear`     | Adds an element to the rear                   | O(1)       |
| `dequeueAtFront`    | Removes an element from the front             | O(1)       |
| `dequeueAtRear`     | Removes an element from the rear              | O(1)       |
| `getFront`          | Retrieves the value of the front element      | O(1)       |
| `getRear`           | Retrieves the value of the rear element       | O(1)       |
| `isEmpty`           | Checks if the deque is empty                  | O(1)       |
| `size`              | Returns the number of elements in the deque   | O(n)       |

---

## Conclusion
This implementation demonstrates how to use a doubly linked list to create an efficient deque. The doubly linked list ensures constant time insertion and deletion from both ends, making it suitable for a wide range of applications.
