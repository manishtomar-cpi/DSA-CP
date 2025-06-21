# Graph BFS (Breadth-First Search)

**Breadth-First Search (BFS)** visits all nodes of a graph level by level. Starting from a given node, it explores all its neighbors before moving to the next level.

---

##  Graph Structure

Text-based diagram:

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

##  Adjacency Matrix

A 5×5 matrix where `matrix[i][j] = 1` indicates an edge between nodes `i` and `j`:

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

###  BFS Algorithm (Matrix Representation)

1. Initialize `visited[5] = {false}`.
2. Use a `queue<int>` to process nodes.
3. Mark the **start node** (e.g., 0) as visited and enqueue it.
4. While the queue is not empty:
   - Dequeue `u`.
   - Print `u`.
   - For each `i` from 0 to 4:
     - If `matrix[u][i] == 1` and `!visited[i]`, mark `i` visited and enqueue `i`.

---

###  Code: BFS using Adjacency Matrix

```cpp
#include <iostream>
#include <queue>

// Perform BFS on an adjacency matrix
void bfs_matrix(int matrix[5][5], int start) {
    bool visited[5] = {false};
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";

        for (int i = 0; i < 5; ++i) {
            if (matrix[u][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
```

---

##  Adjacency List

Each node has a list of its neighbors:

```
0: 1, 2  
1: 0, 3  
2: 0, 3, 4  
3: 1, 2  
4: 2
```

---

###  BFS Algorithm (List Representation)

1. Initialize `visited[5] = {false}`.
2. Use a `queue<int>`.
3. Mark the **start node** (e.g., 0) as visited and enqueue it.
4. While the queue is not empty:
   - Dequeue `u`.
   - Print `u`.
   - For each neighbor `v` in `adj[u]`:
     - If `!visited[v]`, mark it visited and enqueue it.

---

###  Code: BFS using Adjacency List

```cpp
#include <iostream>
#include <vector>
#include <queue>

// Perform BFS on an adjacency list
void bfs_list(const std::vector<int> adj[], int start) {
    bool visited[5] = {false};
    std::queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

---

##  Example Usage

```cpp
int main() {
    // Adjacency Matrix
    int matrix[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    std::cout << "BFS (Matrix): ";
    bfs_matrix(matrix, 0);
    std::cout << "\n";

    // Adjacency List
    std::vector<int> adj[5];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3, 4};
    adj[3] = {1, 2};
    adj[4] = {2};

    std::cout << "BFS (List): ";
    bfs_list(adj, 0);
    std::cout << std::endl;

    return 0;
}
```

---

##  Time Complexity

| Representation | Time Complexity     |
|----------------|---------------------|
| Matrix         | O(V²)               |
| List           | O(V + E)            |

Where `V` = number of vertices, and `E` = number of edges.
