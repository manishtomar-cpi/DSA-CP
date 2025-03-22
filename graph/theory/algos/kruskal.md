# Kruskal's Algorithm

Kruskal's Algorithm is used to find the **Minimum Spanning Tree (MST)** of a graph. It selects the **smallest** edges first while avoiding cycles, ensuring all vertices are connected with the **minimum total weight**.

---

## Steps of Kruskal's Algorithm

1. **Sort all edges** by increasing weight.
2. **Pick the smallest edge** that doesn't form a cycle.
3. **Add the edge to the spanning tree.**
4. **Repeat** until we have (V - 1) edges (where V is the number of vertices).

---

## Example Graph

Let’s say we have this graph:

```
    1       2
 A --- B --- C
 |     |   /
 4|    |5 /3
 |     | /
 D --- E
    6
```

### Edge List (sorted by weight):

| Edge  | Weight |
| ----- | ------ |
| C - E | 3      |
| A - B | 1      |
| B - C | 2      |
| B - E | 5      |
| A - D | 4      |
| D - E | 6      |

---

## Building the Minimum Spanning Tree (MST)

### Step 1: Add the smallest edge

```
C --- E (3)
```

### Step 2: Add next smallest edge

```
C --- E (3)
     /
B --- C (2)
```

### Step 3: Add next smallest edge

```
A --- B (1)
     |
B --- C (2)
     /
C --- E (3)
```

### Step 4: Add next smallest edge

```
A --- B (1)
|    |
D --- C (2)
     /
C --- E (3)
```

**Total Cost:** `1 + 2 + 3 + 4 = 10`

---

## Disjoint Set (Union-Find) in Detail

To efficiently detect cycles, **Kruskal's Algorithm** uses the **Disjoint Set (Union-Find) Data Structure**.

### What is a Disjoint Set?

A **disjoint set** is a data structure that keeps track of elements that are partitioned into separate sets. It supports two main operations:

1. **Find**: Determines which set an element belongs to.
2. **Union**: Merges two sets together.

### How Disjoint Set Works in Kruskal's Algorithm

1. **Each vertex starts as its own set**.
2. **Edges are added one by one**:
   - If both vertices belong to different sets, **they are connected** using **Union**.
   - If they belong to the same set, **adding the edge would form a cycle**, so we skip it.

### Example:

Let’s say we have 5 vertices: `{A, B, C, D, E}`

#### Initial State (Each vertex is its own set):

```
A   B   C   D   E
```

#### Adding Edge (A - B):

```
AB  C   D   E
```

#### Adding Edge (C - D):

```
AB  CD  E
```

#### Adding Edge (B - C):

```
ABCD  E
```

Now, A, B, C, and D are connected. If we try adding an edge between `A` and `D`, it **forms a cycle**, so we **skip it**.

---

## Key Points

- Kruskal’s algorithm **sorts edges** first.
- It uses **Union-Find** to avoid cycles.
- It always **picks the smallest edge first**.
- **Union by Rank** and **Path Compression** make the **Disjoint Set** very efficient.
- The **total weight is minimized**.
