```markdown
<!-- graph_dfs.md -->

# Graph DFS (Depth-First Search)

Depth-First Search (DFS) explores as far as possible along each branch before backtracking, using recursion and a visited tracker.

## Graph

Text-based diagram:

```

```
0
```

/&#x20;
1   2
\ /&#x20;
3   4

```

Edges: (0-1), (0-2), (1-3), (2-3), (2-4)  
Nodes: 0, 1, 2, 3, 4

---

## Adjacency Matrix

A 5×5 matrix where `matrix[i][j] = 1` if there is an edge between `i` and `j`:

```

0 1 2 3 4
0 0 1 1 0 0
1 1 0 0 1 0
2 1 0 0 1 1
3 0 1 1 0 0
4 0 0 1 0 0

````

### DFS Algorithm (Matrix)

1. Create `vector<bool> visited(5, false)`.  
2. Define a recursive helper:  
   - Mark node `u` visited, print `u`.  
   - For `i` from 0 to 4:  
     - If `matrix[u][i] == 1` and `!visited[i]`, recurse on `i`.  
3. Call helper on start node `0`.

### Code

```cpp
#include <iostream>
#include <vector>

// Recursive helper for DFS on adjacency matrix
void dfs_matrix_helper(int u, const std::vector<std::vector<int>>& matrix, std::vector<bool>& visited) {
    visited[u] = true;               // mark current node visited
    std::cout << u << " ";           // process node

    // explore all neighbors of u
    for (int i = 0; i < matrix[u].size(); ++i) {
        if (matrix[u][i] == 1 && !visited[i]) {
            dfs_matrix_helper(i, matrix, visited);  // recurse on unvisited neighbor
        }
    }
}

// DFS using adjacency matrix
void dfs_matrix(const std::vector<std::vector<int>>& matrix) {
    std::vector<bool> visited(5, false);
    dfs_matrix_helper(0, matrix, visited);
}
````

---

## Adjacency List

Each node’s list of neighbors:

```
0: 1, 2
1: 0, 3
2: 0, 3, 4
3: 1, 2
4: 2
```

### DFS Algorithm (List)

1. Create `vector<bool> visited(5, false)`.
2. Define a recursive helper:

   * Mark node `u` visited, print `u`.
   * For each neighbor `v` in `adj[u]`:

     * If `!visited[v]`, recurse on `v`.
3. Call helper on start node `0`.

### Code

```cpp
#include <iostream>
#include <vector>

// Recursive helper for DFS on adjacency list
void dfs_list_helper(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    visited[u] = true;               // mark current node visited
    std::cout << u << " ";           // process node

    // visit each neighbor of u
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs_list_helper(v, adj, visited);  // recurse on unvisited neighbor
        }
    }
}

// DFS using adjacency list
void dfs_list(const std::vector<std::vector<int>>& adj) {
    std::vector<bool> visited(5, false);
    dfs_list_helper(0, adj, visited);
}
```

---

## Example Usage

```cpp
int main() {
    // Adjacency matrix
    std::vector<std::vector<int>> matrix = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,0},
        {0,0,1,0,0}
    };
    std::cout << "DFS (Matrix): ";
    dfs_matrix(matrix);
    std::cout << "\n";

    // Adjacency list
    std::vector<std::vector<int>> adj = {
        {1,2},
        {0,3},
        {0,3,4},
        {1,2},
        {2}
    };
    std::cout << "DFS (List): ";
    dfs_list(adj);
    std::cout << std::endl;

    return 0;
}
```

---

## Time Complexity

* **Matrix**: O(V²)
* **List**: O(V + E)

Where V = number of vertices, E = number of edges.

```
```
