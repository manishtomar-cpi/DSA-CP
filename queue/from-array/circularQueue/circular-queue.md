# Circular Queue

## Introduction
A **circular queue** is a linear data structure in which the last position is connected back to the first position to form a circle. It overcomes the limitation of a standard queue, where elements cannot be added when the rear reaches the end, even if there is free space at the front.

In this implementation, we use a circular queue with a fixed-size array to demonstrate its behavior. Let's break down the key components and logic behind this implementation, focusing on the modulo (`%`) operation.

---

## Why Use Modulo (`%`)?
The modulo operation is used to achieve the circular effect in the queue. It ensures that when the rear or front reaches the end of the array, it wraps around to the beginning.

For example:
- If the array size is `6` and the `rear` reaches `5` (last index), the next enqueue operation wraps the `rear` to index `0`.
- This is achieved using the formula:  
  `rear = (rear + 1) % capacity`

The same logic applies to the `front` during dequeue operations.

---

## Conditions and Their Meanings

### Queue Full Condition
When the queue is full, the `rear` is one step behind the `front` in a circular manner:

```
(rear + 1) % capacity == front
```
This ensures one position is always empty to distinguish between a full and empty queue.

### Queue Empty Condition
The queue is empty when:

```
front == rear
```
In this state, there are no elements in the queue.

---

## Operations Explained

### 1. Enqueue
Adding an element to the queue:
1. Check if the queue is full using the `Queue Full` condition.
2. If not full, move the `rear` pointer forward using:  
   `rear = (rear + 1) % capacity`
3. Insert the new value at `helper_array[rear]`.

### 2. Dequeue
Removing an element from the queue:
1. Check if the queue is empty using the `Queue Empty` condition.
2. If not empty, move the `front` pointer forward using:  
   `front = (front + 1) % capacity`

### 3. Get Front
Retrieve the front element without removing it:
1. Use the formula:  
   `helper_array[(front + 1) % capacity]`

### 4. Get Rear
Retrieve the rear element without removing it:
1. Directly return:  
   `helper_array[rear]`

### 5. Is Empty
Check if the queue is empty:
```
front == rear
```

### 6. Is Full
Check if the queue is full:
```
(rear + 1) % capacity == front
```

---

## Table: Modulo Behavior in Circular Queue

| `capacity` | `front` | `rear` | Operation      | Formula Applied                | New State              |
|------------|---------|--------|----------------|---------------------------------|------------------------|
| 6          | 0       | 0      | Enqueue(5)     | `rear = (rear + 1) % capacity` | `rear = 1`            |
| 6          | 0       | 1      | Enqueue(10)    | `rear = (rear + 1) % capacity` | `rear = 2`            |
| 6          | 2       | 5      | Dequeue        | `front = (front + 1) % capacity` | `front = 3`          |
| 6          | 5       | 0      | Enqueue(20)    | `rear = (rear + 1) % capacity` | `rear = 1` (wraps around) |

---

## Diagram: Circular Queue Visualization
### Initial State
```
[ _ , _ , _ , _ , _ , _ ]
  F                  R
```
### After Enqueue(5)
```
[ _ , 5 , _ , _ , _ , _ ]
  F      R
```
### After Enqueue(10)
```
[ _ , 5 , 10 , _ , _ , _ ]
  F           R
```
### After Dequeue
```
[ _ , _ , 10 , _ , _ , _ ]
         F      R
```
### After Enqueue(20) (wrap-around)
```
[ 20 , _ , 10 , _ , _ , _ ]
  R      F
```

---

## Benefits of Circular Queue
1. **Efficient Space Utilization**: Prevents wastage of space in a static array by reusing freed positions.
2. **Clear Distinction**: The reserved empty slot ensures we can distinguish between full and empty states.
3. **Fast Operations**: Enqueue and dequeue operations have O(1) complexity.

---

## Code Highlights
```cpp
if ((rear + 1) % capacity == front)
{
    cout << "queue full: cannot enqueue" << endl;
}
```
- This checks if the queue is full using the modulo operation.

```cpp
rear = (rear + 1) % capacity;
helper_array[rear] = val;
```
- This updates the rear pointer to the next position in a circular manner and assigns the value.

```cpp
front = (front + 1) % capacity;
```
- This updates the front pointer after a dequeue operation.

---

## Conclusion
The circular queue implementation is a robust way to handle fixed-size data efficiently. The use of the modulo operation makes it possible to "wrap around" the array and reuse unused positions, maximizing space utilization. By understanding and implementing these conditions and formulas, you can create an effective circular queue tailored to your needs.

