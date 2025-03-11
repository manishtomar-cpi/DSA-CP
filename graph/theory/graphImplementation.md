# Graph Implementation in C++

## Introduction
A graph can be implemented in three main ways:
1. **Adjacency Matrix**
2. **Adjacency List**
3. **Edge List**

Each method has its own advantages and disadvantages. Below, we explain each method with a simple example.

---

## 1. Adjacency Matrix
An **Adjacency Matrix** is a 2D array where:
- `matrix[i][j] = 1` if there is an edge between vertex `i` and `j`.
- `matrix[i][j] = 0` if there is no edge.

### Example Graph
```
    (0) --- (1)
     |       |
    (2) --- (3)
```
### Adjacency Matrix Representation
|   | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 0 |
| 1 | 1 | 0 | 0 | 1 |
| 2 | 1 | 0 | 0 | 1 |
| 3 | 0 | 1 | 1 | 0 |

### C++ Implementation
```cpp
#include <iostream>
using namespace std;

#define V 4 // Number of vertices

void printMatrix(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };
    printMatrix(graph);
    return 0;
}
```

---

## 2. Adjacency List
An **Adjacency List** represents a graph using an array of lists.
Each vertex stores a list of its adjacent vertices.

### Example Graph
```
    (0) --- (1)
     |       |
    (2) --- (3)
```
### Adjacency List Representation
| Vertex | Adjacent Vertices |
|--------|------------------|
| 0      | 1, 2            |
| 1      | 0, 3            |
| 2      | 0, 3            |
| 3      | 1, 2            |

### C++ Implementation
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;

    Graph(int V) {
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For an undirected graph
    }

    void printGraph() {
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Vertex " << i << " -> ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    
    g.printGraph();
    return 0;
}
```

---

## 3. Edge List
An **Edge List** represents a graph as a list of edges.
Each edge is stored as a pair `(u, v)`.

### Example Graph
```
    (0) --- (1)
     |       |
    (2) --- (3)
```
### Edge List Representation
| Edge Number | Vertex 1 | Vertex 2 |
|------------|---------|---------|
| 1          | 0       | 1       |
| 2          | 0       | 2       |
| 3          | 1       | 3       |
| 4          | 2       | 3       |

### C++ Implementation
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    vector<pair<int, int>> edgeList;

    void addEdge(int u, int v) {
        edgeList.push_back({u, v});
    }

    void printGraph() {
        for (auto edge : edgeList) {
            cout << "(" << edge.first << ", " << edge.second << ")" << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    
    g.printGraph();
    return 0;
}
```

---

## Comparison of Graph Representations

| Method | Memory Usage | Fast Edge Lookup | Fast Neighbor Lookup | Best for |
|--------|-------------|------------------|----------------------|----------|
| **Adjacency Matrix** | High (`O(V^2)`) | Fast (`O(1)`) | Slow (`O(V)`) | Dense Graphs |
| **Adjacency List** | Moderate (`O(V + E)`) | Slow (`O(V)`) | Fast (`O(E/V)`) | Sparse Graphs |
| **Edge List** | Low (`O(E)`) | Slow (`O(E)`) | Slow (`O(E)`) | Small Graphs |

### Advantages and Disadvantages
| Representation | Advantages | Disadvantages |
|---------------|------------|--------------|
| **Adjacency Matrix** | Simple, Fast lookups | High memory usage |
| **Adjacency List** | Efficient for large graphs | Slower edge lookup |
| **Edge List** | Compact storage | Slow operations |

---

## Conclusion
Each graph representation has its strengths and weaknesses. The choice depends on the type of graph and operations required. 
- **Adjacency Matrix** is good for dense graphs.
- **Adjacency List** is efficient for sparse graphs.
- **Edge List** is useful for compact storage and small graphs.

