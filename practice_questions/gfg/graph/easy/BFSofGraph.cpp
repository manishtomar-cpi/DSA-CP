#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

/*
Breadth-First Search (BFS) Algorithm - Step-by-Step Explanation:

1. Input: An adjacency list 'adj' representing a graph.
   - Each index of 'adj' represents a vertex.
   - Each element is a list of vertices connected to that vertex.

2. Initialize:
   - A result vector 'res' to store the BFS traversal order.
   - An unordered_map 'visited' to track which vertices have been visited.
   - A queue 'vertexes' to help perform BFS level by level.

3. Set all vertices as unvisited initially by assigning 'false' in the visited map.

4. Start BFS traversal from vertex 0:
   - Push vertex 0 to the queue.
   - Mark vertex 0 as visited.

5. While the queue is not empty:
   - Pop the front vertex from the queue and add it to the result list.
   - For each neighbor of the current vertex:
     - If it has not been visited:
       - Push it to the queue.
       - Mark it as visited.

6. Return the result vector containing the order of traversal.

Note: This implementation assumes the graph is connected and starts BFS from vertex 0.
If the graph is disconnected and you want to visit all components, you would need to run BFS for each unvisited node.
*/

vector<int> bfs(vector<vector<int>> &adj)
{

    vector<int> res;
    unordered_map<int, bool> visited;
    queue<int> vertexes;
    for (int i = 0; i < adj.size(); i++)
    {
        visited[i] = false;
    }

    vertexes.push(0);
    visited[0] = true;
    while (!vertexes.empty())
    {
        int current = vertexes.front();
        vertexes.pop();
        res.push_back(current);
        for (int i = 0; i < adj[current].size(); i++)
        {
            if (!visited[adj[current][i]])
            {
                vertexes.push(adj[current][i]);
                visited[adj[current][i]] = true;
            }
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> matrix = {

        {4, 5}, // neighbors of vertex 0
        {2},    // neighbors of vertex 1
        {1, 5}, // neighbors of vertex 2
        {4},    // neighbors of vertex 3
        {0, 3}, // neighbors of vertex 4
        {0, 2}  // neighbors of vertex 5
    };
    bfs(matrix);

    return 0;
}