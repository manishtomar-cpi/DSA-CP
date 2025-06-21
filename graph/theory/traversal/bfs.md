# Graph BFS (Breadth-First Search)

Breadth-First Search (BFS) is an algorithm used to explore nodes of a graph level by level. It starts from a selected node and explores all its neighbors before moving to the next level of nodes.

------------------------------------------------------------
Graph Diagram (Undirected)

    0
   / \
  1   2
   \ / \
    3   4

Edges: (0-1), (0-2), (1-3), (2-3), (2-4)
------------------------------------------------------------

We will represent this graph in two ways:
1. Adjacency Matrix
2. Adjacency List

Then we will perform BFS traversal on both.

------------------------------------------------------------
1. BFS using Adjacency Matrix
------------------------------------------------------------

Adjacency Matrix (5 nodes):
Matrix[i][j] = 1 if there is an edge between i and j

        0 1 2 3 4
      ------------
    0| 0 1 1 0 0
    1| 1 0 0 1 0
    2| 1 0 0 1 1
    3| 0 1 1 0 0
    4| 0 0 1 0 0

Code (C++ Style):

#include <iostream>
#include <queue>
using namespace std;

void bfs_matrix(int graph[5][5], int start) {
    bool visited[5] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < 5; i++) {
            if (graph[node][i] == 1 && visited[i] == false) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

------------------------------------------------------------
2. BFS using Adjacency List
------------------------------------------------------------

Adjacency List (5 nodes):

    0: 1 2
    1: 0 3
    2: 0 3 4
    3: 1 2
    4: 2

Code (C++ Style):

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs_list(vector<int> graph[], int start) {
    bool visited[5] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int i = 0; i < graph[node].size(); i++) {
            int neighbor = graph[node][i];
            if (visited[neighbor] == false) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

------------------------------------------------------------
Main Function to Run Both

int main() {
    // Adjacency Matrix
    int matrix[5][5] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,1,1},
        {0,1,1,0,0},
        {0,0,1,0,0}
    };
    cout << "BFS using Adjacency Matrix: ";
    bfs_matrix(matrix, 0);
    cout << endl;

    // Adjacency List
    vector<int> list[5];
    list[0].push_back(1);
    list[0].push_back(2);
    list[1].push_back(0);
    list[1].push_back(3);
    list[2].push_back(0);
    list[2].push_back(3);
    list[2].push_back(4);
    list[3].push_back(1);
    list[3].push_back(2);
    list[4].push_back(2);

    cout << "BFS using Adjacency List: ";
    bfs_list(list, 0);
    cout << endl;

    return 0;
}

------------------------------------------------------------
Expected Output:

BFS using Adjacency Matrix: 0 1 2 3 4  
BFS using Adjacency List: 0 1 2 3 4

------------------------------------------------------------
Time Complexity:

- BFS using Adjacency Matrix: O(V^2)
- BFS using Adjacency List: O(V + E)

Where V = number of vertices, E = number of edges

------------------------------------------------------------
Summary:

- BFS explores graph level by level.
- Use a queue to maintain the order of visiting nodes.
- Adjacency List is more efficient for sparse graphs.
- Adjacency Matrix is easier to implement but uses more space.
