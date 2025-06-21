# Graph DFS (Depth-First Search)

Depth-First Search (DFS) is an algorithm for traversing or searching graph data structures. It explores as far as possible along each branch before backtracking.

---

## Graph Structure

We will perform DFS on the following undirected graph:

```
      0
     / \
    1   2
     \ / \
      3   4
```

- **Edges**: (0–1), (0–2), (1–3), (2–3), (2–4)
- **Nodes**: 0, 1, 2, 3, 4

---

## Adjacency Matrix

The graph can be represented using a 5×5 adjacency matrix:

```
    0 1 2 3 4
  ------------
0 | 0 1 1 0 0
1 | 1 0 0 1 0
2 | 1 0 0 1 1
3 | 0 1 1 0 0
4 | 0 0 1 0 0
```

---

## DFS Algorithm (Matrix Representation)

1. Initialize `visited[5] = {false}`.
2. Start DFS from a given node (e.g., node 0).
3. Mark the current node as visited and print it.
4. Recursively visit all its unvisited adjacent nodes.

---

### Code: DFS using Adjacency Matrix

```cpp
#include <iostream>

void dfs_matrix(int matrix[5][5], bool visited[5], int u) {
    visited[u] = true;
    std::cout << u << " ";

    for (int v = 0; v < 5; ++v) {
        if (matrix[u][v] == 1 && !visited[v]) {
            dfs_matrix(matrix, visited, v);
        }
    }
}
```

---

## Adjacency List

Graph represented as an adjacency list:

```
0: 1, 2  
1: 0, 3  
2: 0, 3, 4  
3: 1, 2  
4: 2
```

---

## DFS Algorithm (List Representation)

1. Initialize `visited[5] = {false}`.
2. Start DFS from a given node (e.g., node 0).
3. Mark the current node as visited and print it.
4. For each unvisited neighbor of the current node, call DFS recursively.

---

### Code: DFS using Adjacency List

```cpp
#include <iostream>
#include <vector>

void dfs_list(const std::vector<int> adj[], bool visited[5], int u) {
    visited[u] = true;
    std::cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs_list(adj, visited, v);
        }
    }
}
```

---

## Example Usage

```cpp
int main() {
    // DFS using Adjacency Matrix
    int matrix[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    bool visited_matrix[5] = {false};
    std::cout << "DFS (Matrix): ";
    dfs_matrix(matrix, visited_matrix, 0);
    std::cout << "\n";

    // DFS using Adjacency List
    std::vector<int> adj[5];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3, 4};
    adj[3] = {1, 2};
    adj[4] = {2};
    bool visited_list[5] = {false};
    std::cout << "DFS (List): ";
    dfs_list(adj, visited_list, 0);
    std::cout << std::endl;

    return 0;
}
```

---

## Time Complexity

| Representation | Time Complexity     |
|----------------|---------------------|
| Matrix         | O(V²)               |
| List           | O(V + E)            |

Where `V` is the number of vertices and `E` is the number of edges.
