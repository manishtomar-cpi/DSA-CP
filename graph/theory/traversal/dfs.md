Here are the two updated Markdown files in correct format, each shown as a single fenced code block containing the full contents. You can copy each block into its own `.md` file (`graph_bfs.md` and `graph_dfs.md`).

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

    visited[start] = true;  // start node
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";

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

````

```markdown
<!-- graph_dfs.md -->

# Graph DFS (Depth-First Search)

Depth-First Search (DFS) explores as far as possible along each branch before backtracking, using recursion and a visited tracker.

## Graph

Text-based diagram:

````

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

```

0 1 2 3 4
0 0 1 1 0 0
1 1 0 0 1 0
2 1 0 0 1 1
3 0 1 1 0 0
4 0 0 1 0 0

```

## Adjacency List

```

0: 1, 2
1: 0, 3
2: 0, 3, 4
3: 1, 2
4: 2

````

---

## DFS Algorithm (Matrix)

1. Create `bool visited[5] = {false}`.
2. Mark start node `0` visited, call recursive helper.
3. In helper for node `u`:
   - Print `u`.
   - For `i` from 0 to 4:
     - If `matrix[u][i] == 1` and `!visited[i]`, mark visited and recurse on `i`.

### Code

```cpp
#include <iostream>
#include <vector>

// Recursive DFS for adjacency matrix
void dfs_matrix_helper(int u, std::vector<std::vector<int>>& matrix, std::vector<bool>& visited) {
    std::cout << u << " ";      // process node
    visited[u] = true;          // mark visited

    // Explore all possible neighbors
    for (int i = 0; i < matrix[u].size(); ++i) {
        if (matrix[u][i] == 1 && !visited[i]) {
            dfs_matrix_helper(i, matrix, visited);  // recurse
        }
    }
}

void dfs_matrix(std::vector<std::vector<int>>& matrix) {
    std::vector<bool> visited(5, false);
    dfs_matrix_helper(0, matrix, visited);
}
````

---

## DFS Algorithm (List)

1. Create `bool visited[5] = {false}`.
2. Mark start node `0` visited, call recursive helper.
3. In helper for node `u`:

   * Print `u`.
   * For each neighbor `v` in `adj[u]`:

     * If `!visited[v]`, mark visited and recurse on `v`.

### Code

```cpp
#include <iostream>
#include <vector>

// Recursive DFS for adjacency list
void dfs_list_helper(int u, const std::vector<std::vector<int>>& adj, std::vector<bool>& visited) {
    std::cout << u << " ";      // process node
    visited[u] = true;          // mark visited

    // Visit each neighbor
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs_list_helper(v, adj, visited);  // recurse
        }
    }
}

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

Feel free to save each block directly as `graph_bfs.md` and `graph_dfs.md`.
```
