# Graph Data Structure in C++

## Introduction
A **graph** is a non-linear data structure consisting of **vertices (nodes)** and **edges (connections)**. Graphs are used to model relationships in various real-world problems, such as social networks, navigation systems, and computer networks.

## Graph Terminology
Below is a table summarizing key terms in graph theory:

| Term             | Description |
|-----------------|-------------|
| **Vertex (Node)** | A fundamental unit of a graph that represents an entity. Denoted as `V`. |
| **Edge**         | A connection between two vertices. Denoted as `E`. |
| **Adjacency List** | A representation of a graph using lists to store neighboring nodes. Or if there is the direct edge b/w any vertices. |
| **Adjacency Matrix** | A representation of a graph using a matrix to indicate connections between nodes. |
| **Directed Graph** | A graph where edges have a direction, meaning `A → B` is not the same as `B → A`. |
| **Undirected Graph** | A graph where edges have no direction, meaning `A — B` is the same as `B — A`. |
| **Weighted Graph** | A graph where edges have associated weights (cost, distance, etc.). |
| **Unweighted Graph** | A graph where all edges have the same weight (or no weight). |
| **Degree of a Vertex** | The number of edges connected to a vertex. |
| **Path** | A sequence of edges connecting a sequence of vertices. or if there are any path from one vertex to another |
| **Cycle** | A path that starts and ends at the same vertex without repeating any edge. |
| **Connected Graph** | A graph where there is a path between any two pair of vertices. |
| **Disconnected Graph** | A graph where at least one vertex is not connected to others. |
| **Tree** | A special type of graph with no cycles and exactly `V-1` edges. |

## Types of Graphs with Diagrams

### 1. **Undirected Graph**
```
    A --- B
    |     |
    C --- D
```
This graph has edges `{A-B, B-D, D-C, C-A}`.

### 2. **Directed Graph (Digraph)**
```
    A → B
    ↓   ↓
    C → D
```
Here, edges have directions: `{A→B, A→C, B→D, C→D}`.

### 3. **Weighted Graph**
```
    A --(2)-- B
    |         |
  (3)       (5)
    |         |
    C --(1)-- D
```
The numbers on edges represent weights (cost, distance, etc.).

## Graph Representation in C++
Graphs can be represented in two common ways:

### 1. **Adjacency Matrix Representation**
```cpp
#include <iostream>
using namespace std;

#define V 4  // Number of vertices

void printGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0}
    };
    printGraph(graph);
    return 0;
}
```

### 2. **Adjacency List Representation**
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
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    
    g.printGraph();
    return 0;
}
```

## Graph Traversal Algorithms
Graphs can be traversed using:

### 1. **Depth-First Search (DFS)** (Recursive Implementation)
```cpp
#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& adj, vector<bool>& visited, int node) {
    cout << node << " ";
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(adj, visited, neighbor);
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    
    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    DFS(adj, visited, 0);
    return 0;
}
```

### 2. **Breadth-First Search (BFS)**
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    
    cout << "BFS Traversal: ";
    BFS(adj, 0);
    return 0;
}
```




