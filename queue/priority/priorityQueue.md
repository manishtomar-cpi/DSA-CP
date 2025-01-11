# Priority Queue Implementation with Doubly Linked List

This document provides a detailed explanation of the implementation of a **Priority Queue** using a doubly linked list. The code includes functionalities for enqueueing, dequeueing, displaying the queue, and retrieving elements with the highest and lowest priorities. 

## What is a Priority Queue?
A **priority queue** is a type of queue in which each element is associated with a priority value. Elements are dequeued based on their priority, not just their order of insertion. Typically, elements with higher priority are dequeued before elements with lower priority. In case of elements with the same priority, the insertion order is preserved (FIFO behavior).

### Key Features:
1. **Priority-Based Ordering**:
   - Elements are ordered based on their priority.
   - Higher priority elements are served first.

2. **Dynamic Behavior**:
   - Supports dynamic addition and removal of elements.
   - Automatically adjusts the order based on priorities.

3. **Use Cases**:
   - Task scheduling (e.g., CPU scheduling).
   - Simulation systems (e.g., event-based simulation).
   - Pathfinding algorithms (e.g., Dijkstra's algorithm).

## Code Overview
The priority queue is implemented using a doubly linked list to efficiently manage priorities while maintaining a sorted structure.

### **Key Components**
1. **Node Class**:
   - Represents a single element in the priority queue.
   - Each node stores:
     - `data`: The value of the node.
     - `priority`: The priority of the node (higher number indicates higher priority).
     - `next`: Pointer to the next node.
     - `prev`: Pointer to the previous node.

2. **PriorityQueue Class**:
   - Manages the nodes and provides the following functionalities:
     - `enqueue`: Adds an element to the queue based on priority.
     - `dequeue`: Removes the element with the highest priority.
     - `displayQueue`: Displays the current state of the queue.
     - `higherPriority`: Returns the data of the node with the highest priority.
     - `lowestPriority`: Returns the data of the node with the lowest priority.
     - Destructor: Cleans up memory by deleting all nodes.

## Functionalities Explained
### **Enqueue**
Adds an element to the queue in the correct position based on its priority.
- If the queue is empty, the new node becomes the `front`.
- If the new node has higher priority than the current front, it is inserted at the front.
- Otherwise, the queue is traversed to find the correct position for insertion.

#### Diagram:
1. Before enqueueing `(11, P7)`:
```
(7, P9) <-> (8, P6) <-> (6, P6)
```
2. After enqueueing `(11, P7)`:
```
(7, P9) <-> (11, P7) <-> (8, P6) <-> (6, P6)
```

#### Code Snippet:
```cpp
void enqueue(int data, int priority)
{
    Node *temp = new Node(data, priority);
    if (front == nullptr)
    {
        front = temp;
    }
    else if (front->priority < priority)
    {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
    else
    {
        Node *temp1 = front;
        while (temp1->next && temp1->next->priority >= priority)
        {
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp->prev = temp1;
        if (temp1->next)
        {
            temp1->next->prev = temp;
        }
        temp1->next = temp;
    }
    displayQueue();
}
```

---

### **Dequeue**
Removes the element with the highest priority from the queue (front node).
- If the queue is empty, a message is displayed.
- Otherwise, the front node is removed, and `front` is updated to the next node.

#### Diagram:
1. Before dequeue:
```
(7, P9) <-> (11, P7) <-> (8, P6) <-> (6, P6)
```
2. After dequeue:
```
(11, P7) <-> (8, P6) <-> (6, P6)
```

#### Code Snippet:
```cpp
void dequeue()
{
    if (front == nullptr)
    {
        cout << "queue empty!" << endl;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        if (front)
        {
            front->prev = nullptr;
        }
        delete temp;
        displayQueue();
    }
}
```

---

### **DisplayQueue**
Displays the current state of the queue in a readable format.
- Traverses the queue from `front` to `rear` and prints each node's data and priority.

#### Example Output:
```
Priority Queue: [ (7, P9) -> (11, P7) -> (8, P6) -> (6, P6) ]
```

#### Code Snippet:
```cpp
void displayQueue()
{
    if (front == nullptr)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        Node *temp = front;
        cout << "Priority Queue: [ ";
        while (temp != nullptr)
        {
            cout << "(" << temp->data << ", P" << temp->priority << ")";
            temp = temp->next;
            if (temp != nullptr)
                cout << " -> ";
        }
        cout << " ]" << endl;
    }
}
```

---

### **HigherPriority**
Returns the data of the node with the highest priority (front node).

#### Code Snippet:
```cpp
int higherPriority()
{
    return (!front) ? -1 : front->data;
}
```

---

### **LowestPriority**
Returns the data of the node with the lowest priority (rear node).

#### Code Snippet:
```cpp
int lowestPriority()
{
    if (front == nullptr)
    {
        return -1;
    }
    else
    {
        Node *temp = front;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}
```

---

## Example Execution
### Input Code:
```cpp
int main()
{
    PriorityQueue p1;

    p1.enqueue(7, 9); // (7, P9)
    p1.enqueue(8, 6); // (7, P9) -> (8, P6)
    p1.enqueue(6, 6); // (7, P9) -> (8, P6) -> (6, P6)
    p1.enqueue(11, 7); // (7, P9) -> (11, P7) -> (8, P6) -> (6, P6)
    p1.dequeue(); // (11, P7) -> (8, P6) -> (6, P6)
    cout << p1.higherPriority() << endl; // 11
    cout << p1.lowestPriority() << endl; // 6

    return 0;
}
```

### Output:
```
7 enqueued!
Priority Queue: [ (7, P9) ]
8 enqueued!
Priority Queue: [ (7, P9) -> (8, P6) ]
6 enqueued!
Priority Queue: [ (7, P9) -> (8, P6) -> (6, P6) ]
11 enqueued!
Priority Queue: [ (7, P9) -> (11, P7) -> (8, P6) -> (6, P6) ]
dequeued: 7
Priority Queue: [ (11, P7) -> (8, P6) -> (6, P6) ]
11
6
```

---

## Summary Table
| Function            | Description                                    | Complexity |
|---------------------|------------------------------------------------|------------|
| `enqueue`           | Adds an element to the queue based on priority | O(n)       |
| `dequeue`           | Removes the element with the highest priority  | O(1)       |
| `displayQueue`      | Prints the entire queue                       | O(n)       |
| `higherPriority`    | Returns the data of the front node             | O(1)       |
| `lowestPriority`    | Returns the data of the rear node              | O(n)       |

---

## Conclusion
This implementation demonstrates how to use a doubly linked list to create an efficient priority queue. The use of a doubly linked list ensures dynamic memory allocation and provides efficient traversal for inserting nodes based on priority. The code includes clear output for debugging and supports all basic priority queue operations.
