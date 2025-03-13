# Prim's Algorithm - Minimum Spanning Tree (MST)

## Introduction
Prim's Algorithm is a greedy algorithm used to find the Minimum Spanning Tree (MST) of a weighted, connected, and undirected graph. The algorithm starts from an arbitrary node and expands the tree by selecting the edge with the minimum weight that connects a new vertex to the growing MST.

## Key Concepts
- **Minimum Spanning Tree (MST)**: A subset of the edges that connects all vertices with the minimum possible total edge weight and without any cycles.
- **Greedy Choice**: The algorithm picks the smallest edge that expands the MST.
- **Near Array**: Maintains the nearest vertices not yet included in the MST.

## Steps of Prim's Algorithm
1. Initialize the spanning tree with a single vertex.
2. Find the edge with the minimum weight connecting a vertex in the MST to a vertex outside.
3. Add the selected edge and vertex to the MST.
4. Update the "near" array for all vertices.
5. Repeat steps 2–4 until all vertices are included in the MST.

## Example Graph
Consider the following weighted graph:

```
     (0)
     /   \
    4     8
   /       \
  (1)------(2)
   | \    /  |  
   |  2  6   |  
   | /    \  |  
  (3)------(4)
       9   
```

### Graph Representation in Matrix Form
|   | 0 | 1 | 2 | 3 | 4 |
|---|---|---|---|---|---|
| 0 | ∞ | 4 | 8 | ∞ | ∞ |
| 1 | 4 | ∞ | 6 | 2 | ∞ |
| 2 | 8 | 6 | ∞ | ∞ | 9 |
| 3 | ∞ | 2 | ∞ | ∞ | 6 |
| 4 | ∞ | ∞ | 9 | 6 | ∞ |

## Execution of Prim's Algorithm

### Step 1: Select Minimum Edge
Choose the edge with the smallest weight.
- **Selected Edge**: (1,3) → Weight = **2**
- **MST**: {(1,3)}
- **Near Array Updated**

### Step 2: Find Next Minimum Edge
- **Candidates**: (1,0) = 4, (1,2) = 6, (3,4) = 6
- **Selected Edge**: (1,0) → Weight = **4**
- **MST**: {(1,3), (1,0)}

### Step 3: Find Next Minimum Edge
- **Candidates**: (1,2) = 6, (3,4) = 6
- **Selected Edge**: (3,4) → Weight = **6**
- **MST**: {(1,3), (1,0), (3,4)}

### Step 4: Find Next Minimum Edge
- **Candidates**: (1,2) = 6, (4,2) = 9
- **Selected Edge**: (1,2) → Weight = **6**
- **MST**: {(1,3), (1,0), (3,4), (1,2)}

### Step 5: Find Next Minimum Edge
- **Selected Edge**: (4,2) → Weight = **9**
- **Final MST**: {(1,3), (1,0), (3,4), (1,2), (4,2)}

### Minimum Cost of Spanning Tree
```
Cost = 2 + 4 + 6 + 6 + 9 = 27
```

## Time Complexity
- **Using Adjacency Matrix**: O(V²)
- **Using Priority Queue with Min-Heap**: O(E log V) (Faster implementation)

## Conclusion
Prim’s Algorithm efficiently finds the MST for a given graph using a greedy approach. The algorithm ensures that all nodes are connected while minimizing the total edge weight.

