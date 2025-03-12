# Spanning Tree

A **Spanning Tree** is a subgraph of a graph that connects all vertices without forming cycles. It is a **minimum subset** of edges from the original graph that still ensures all nodes are connected.

## Properties of a Spanning Tree
- It contains **all vertices** of the original graph.
- It is **connected**, meaning there is a path between any two nodes.
- It has **no cycles**, meaning it is a tree.
- If a graph has **N vertices**, then a spanning tree has **N-1 edges**.

## Example of a Spanning Tree
Consider the following graph:

```
     1-----2
    /|     |\
   3 |     | 4
    \|     |/
     5-----6
```

### Possible Spanning Tree
A spanning tree removes some edges while keeping all vertices connected:

```
     1-----2
    /       \
   3         4
    \       /
     5-----6
```

Here, we removed some edges to avoid cycles while maintaining connectivity.

## Types of Spanning Trees

### 1. **Minimum Spanning Tree (MST)**
A **Minimum Spanning Tree** (MST) is a spanning tree where the sum of edge weights is minimized.

### 2. **Maximum Spanning Tree**
A **Maximum Spanning Tree** is a spanning tree where the sum of edge weights is maximized.

## Algorithms for Finding Spanning Trees

### 1. **Kruskal's Algorithm**
- **Steps**:
  1. Sort all edges in **ascending order** of weight.
  2. Pick the smallest edge and check if adding it forms a cycle.
  3. If no cycle is formed, add it to the tree.
  4. Repeat until all vertices are connected.

**Example:**
Given a weighted graph:

```
   (1)---2---(2)
    |         |
    4         3
    |         |
   (3)---1---(4)
```

The **MST using Kruskal's Algorithm**:

```
   (1)---2---(2)
            |
            3
            |
   (3)---1---(4)
```

Total weight = **2 + 1 + 3 = 6**

### 2. **Prim's Algorithm**
- **Steps**:
  1. Pick any node as the starting point.
  2. Select the smallest edge connected to the tree.
  3. Repeat until all nodes are connected.

## Applications of Spanning Trees
- **Network Design**: Minimum cost wiring and fiber optic networks.
- **Image Segmentation**: Reducing edges in image processing.
- **Clustering Algorithms**: Used in unsupervised learning to connect clusters.

## Conclusion
A spanning tree is a fundamental concept in graph theory that ensures connectivity with the minimum number of edges. **Minimum Spanning Trees (MST)** help in optimizing networks, reducing costs, and solving various real-world problems.

