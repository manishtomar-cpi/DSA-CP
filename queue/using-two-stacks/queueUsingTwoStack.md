# Queue Implementation Using Two Stacks

The implementation leverages the **LIFO** (Last In, First Out) behavior of stacks to simulate the **FIFO** (First In, First Out) behavior of a queue. Each operation is explained with diagrams to illustrate the transformations in the stacks during enqueue and dequeue operations.


## Concept of Queue Using Two Stacks
This implementation uses two stacks (**s1** and **s2**) to simulate the behavior of a queue.

### **How it works**:
- **Stack 1 (s1)**: Used for enqueue operations.
- **Stack 2 (s2)**: Used for dequeue operations.

The operations are divided as follows:
1. **Enqueue**: Push the element into `s1`.
2. **Dequeue**:
   - If `s2` is empty, transfer all elements from `s1` to `s2` (this reverses the order).
   - Pop the top element from `s2`.
3. **Get Front**: The top element of `s2` (if non-empty) or the first transferred element from `s1`.
4. **Get Rear**: The top element of `s1` (if non-empty) or the last transferred element from `s2`.

---

## Example Execution
Let's go through the operations step by step:

### **Initial State**
- **Stack 1 (s1)**: Empty
- **Stack 2 (s2)**: Empty

---

### **Operation 1: Dequeue**
- Attempting to dequeue from an empty queue.
- **Output**: "Queue Empty: cannot dequeue!"

#### **Diagram**:
```
Stack 1 (s1): []
Stack 2 (s2): []
```

---

### **Operation 2: Enqueue 10**
- Push `10` into `s1`.

#### **Diagram**:
```
Stack 1 (s1):
[10]

Stack 2 (s2):
[]
```

---

### **Operation 3: Enqueue 20**
- Push `20` into `s1`.

#### **Diagram**:
```
Stack 1 (s1):
[20]
[10]

Stack 2 (s2):
[]
```

---

### **Operation 4: Enqueue 30**
- Push `30` into `s1`.

#### **Diagram**:
```
Stack 1 (s1):
[30]
[20]
[10]

Stack 2 (s2):
[]
```

---

### **Operation 5: Dequeue**
1. Check if `s2` is empty.
2. Since `s2` is empty, transfer all elements from `s1` to `s2`:
   - Pop `10` from `s1` and push into `s2`.
   - Pop `20` from `s1` and push into `s2`.
   - Pop `30` from `s1` and push into `s2`.
3. Pop the top element (`10`) from `s2`.

#### **Diagram After Transfer**:
```
Stack 1 (s1):
[]

Stack 2 (s2):
[10]
[20]
[30]
```
#### **Diagram After Dequeue**:
```
Stack 1 (s1):
[]

Stack 2 (s2):
[20]
[30]
```
- **Output**: "dequeued: 10!"

---

### **Operation 6: Enqueue 40**
- Push `40` into `s1`.

#### **Diagram**:
```
Stack 1 (s1):
[40]

Stack 2 (s2):
[20]
[30]
```

---

### **Operation 7: Dequeue**
1. Check if `s2` is empty.
2. Since `s2` is not empty, pop the top element (`20`) from `s2`.

#### **Diagram After Dequeue**:
```
Stack 1 (s1):
[40]

Stack 2 (s2):
[30]
```
- **Output**: "dequeued: 20!"

---

### **Operation 8: Get Front**
1. Check if `s2` is empty.
2. Since `s2` is not empty, the front element is the top of `s2` (`30`).

#### **Diagram**:
```
Stack 1 (s1):
[40]

Stack 2 (s2):
[30]
```
- **Output**:
```
30
```

---

### **Operation 9: Get Rear**
1. Check if `s1` is empty.
2. Since `s1` is not empty, the rear element is the top of `s1` (`40`).

#### **Diagram**:
```
Stack 1 (s1):
[40]

Stack 2 (s2):
[30]
```
- **Output**:
```
40
```

---

## Final State
- **Stack 1 (s1)**: [40]
- **Stack 2 (s2)**: [30]

---

## Summary Table
| Function        | Description                                  | Time Complexity |
|-----------------|----------------------------------------------|-----------------|
| `enqueue`       | Pushes an element into `s1`.                 | O(1)            |
| `dequeue`       | Transfers elements from `s1` to `s2` if `s2` is empty, then pops from `s2`. | O(n) in worst case |
| `getFront`      | Retrieves the front element of the queue.    | O(n) in worst case |
| `getRear`       | Retrieves the rear element of the queue.     | O(n) in worst case |

---

## Conclusion
This implementation demonstrates how to use two stacks to simulate the behavior of a queue. The enqueue operation is efficient (\(O(1)\)), while the dequeue and front/rear retrieval operations can have a higher cost (\(O(n)\)) when transfers between stacks are required. The approach provides a good understanding of how stack-based operations can emulate different data structures.
