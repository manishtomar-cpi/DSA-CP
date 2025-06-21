```markdown
<!-- graph_bfs.md -->

# Graph BFS (Breadth-First Search)

Breadth-First Search (BFS) visits all nodes of a graph level by level, starting from a given node and exploring all its neighbors before moving deeper.

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

### BFS Algorithm (Matrix)

1. Create `bool visited[5] = {false}`.  
2. Use a `queue<int>` to track nodes.  
3. Mark the start node `0` as visited and enqueue it.  
4. While the queue is not empty:  
   - Dequeue `u`.  
   - Print `u`.  
   - For `i` from 0 to 4:  
     - If `matrix[u][i] == 1` and `!visited[i]`, mark `i` visited and enqueue `i`.  

### Code

```cpp
#include <iostream>
#include <queue>

// Perform BFS on an adjacency matrix
void bfs_matrix(int matrix[5][5], int start) {
    bool visited[5] = {false};
    std::queue<int> q;

    // Start from 'start'
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";  // process node

        // Explore all possible neighbors
        for (int i = 0; i < 5; ++i) {
            if (matrix[u][i] == 1 && !visited[i]) {
                visited[i] = true;  // mark visited
                q.push(i);          // enqueue
            }
        }
    }
}
````

---

## Adjacency List

Each node has a list of its neighbors:

```
0: 1, 2
1: 0, 3
2: 0, 3, 4
3: 1, 2
4: 2
```

### BFS Algorithm (List)

1. Create `bool visited[5] = {false}`.
2. Use a `queue<int>`.
3. Mark `0` as visited and enqueue.
4. While the queue is not empty:

   * Dequeue `u`.
   * Print `u`.
   * For each neighbor `v` in `adj[u]`:

     * If `!visited[v]`, mark visited and enqueue.

### Code

```cpp
#include <iostream>
#include <vector>
#include <queue>

// Perform BFS on an adjacency list
void bfs_list(const std::vector<int> adj[], int start) {
    bool visited[5] = {false};
    std::queue<int> q;

    // Start from 'start'
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";  // process node

        // Visit each neighbor
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;  // mark visited
                q.push(v);          // enqueue
            }
        }
    }
}
```

---

## Example Usage

```cpp
int main() {
    // Adjacency matrix
    int matrix[5][5] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,0},
        {0,0,1,0,0}
    };
    std::cout << "BFS (Matrix): ";
    bfs_matrix(matrix, 0);
    std::cout << "\n";

    // Adjacency list
    std::vector<int> adj[5];
    adj[0] = {1,2};
    adj[1] = {0,3};
    adj[2] = {0,3,4};
    adj[3] = {1,2};
    adj[4] = {2};
    std::cout << "BFS (List): ";
    bfs_list(adj, 0);
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
