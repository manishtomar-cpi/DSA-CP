#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

/*
Depth-First Search (DFS) Algorithm - Step-by-Step Explanation:

1. Input: An adjacency list 'adj' representing a graph.
   - Each index of 'adj' represents a node.
   - Each element is a list of adjacent (neighbor) nodes.

2. The 'dfs' function starts the traversal from node 0:
   - Push node 0 to the result vector 'res'.
   - Mark node 0 as visited in the 'visited' map.

3. The 'dfs_helper' function is a recursive helper:
   - For the current node, it checks each of its neighbors.
   - If a neighbor has not been visited:
     - Add it to the result vector.
     - Mark it as visited.
     - Recursively call 'dfs_helper' on that neighbor.

4. This continues until all reachable nodes from the starting node are visited.

5. The result vector 'res' contains the order in which nodes were visited using DFS.

Note:
- This implementation assumes the graph is connected and starts DFS from node 0.
- If the graph is disconnected and you want to visit all components, you should call dfs_helper for each unvisited node.
*/

class Solution
{
public:
    vector<int> res;
    unordered_map<int, bool> visited;
    void dfs_helper(int startingIndex, vector<vector<int>> &adj)
    {
        for (int i = 0; i < adj[startingIndex].size(); i++)
        {
            int neighbor = adj[startingIndex][i];
            if (!visited[neighbor])
            {
                res.push_back(neighbor);
                visited[neighbor] = true;
                dfs_helper(neighbor, adj);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Code here
        res.push_back(0);
        visited[0] = true;
        dfs_helper(0, adj);

        return res;
    }
};
int main()
{
    vector<vector<int>> adj = {
        {1, 2, 4, 8}, // Node 0
        {0, 5, 6, 9}, // Node 1
        {0, 4},       // Node 2
        {7, 8},       // Node 3
        {0, 2},       // Node 4
        {1, 8},       // Node 5
        {1, 7, 9},    // Node 6
        {3, 6},       // Node 7
        {0, 3, 5},    // Node 8
        {1, 6}        // Node 9
    };

    Solution s1;
    s1.dfs(adj);

    return 0;
}