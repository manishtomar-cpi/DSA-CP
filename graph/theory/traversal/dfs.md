# Graph DFS (Depth-First Search) using Adjacency List and Adjacency Matrix

DFS (Depth-First Search) is a graph traversal algorithm. It explores as far as possible along each path before backtracking. It uses recursion and a visited tracker.

------------------------------------------------------------
Graph Diagram (Undirected)

    0
   / \
  1   2
   \ / \
    3   4

Edges: (0-1), (0-2), (1-3), (2-3), (2-4)

Graph has 5 nodes: 0 to 4
------------------------------------------------------------

We will implement DFS using:
1. Adjacency List
2. Adjacency Matrix

Both versions are written using a class and simple helper functions.

------------------------------------------------------------
Code in C++ (with simple comments)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> res_list; // stores DFS result for list
    unordered_map<int, bool> visited_list; // tracks visited nodes in list

    vector<int> res_matrix; // stores DFS result for matrix
    unordered_map<int, bool> visited_matrix; // tracks visited nodes in matrix

    // Helper function for DFS using adjacency list
    void dfs_list_helper(int node, vector<vector<int>>& adj) {
        // Loop through all neighbors of the current node
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];
            // If neighbor is not visited, visit it
            if (!visited_list[neighbor]) {
                res_list.push_back(neighbor);         // add to result
                visited_list[neighbor] = true;        // mark visited
                dfs_list_helper(neighbor, adj);       // recurse
            }
        }
    }

    // DFS function using adjacency list
    vector<int> dfs_using_list(vector<vector<int>>& adj) {
        res_list.clear();
        visited_list.clear();

        res_list.push_back(0);        // start from node 0
        visited_list[0] = true;       // mark as visited
        dfs_list_helper(0, adj);      // call helper

        return res_list;
    }

    // Helper function for DFS using adjacency matrix
    void dfs_matrix_helper(int node, vector<vector<int>>& matrix) {
        // Loop through all nodes to check connection
        for (int i = 0; i < matrix[node].size(); i++) {
            // If there is an edge and node not visited
            if (matrix[node][i] == 1 && !visited_matrix[i]) {
                res_matrix.push_back(i);              // add to result
                visited_matrix[i] = true;             // mark visited
                dfs_matrix_helper(i, matrix);         // recurse
            }
        }
    }

    // DFS function using adjacency matrix
    vector<int> dfs_using_matrix(vector<vector<int>>& matrix) {
        res_matrix.clear();
        visited_matrix.clear();

        res_matrix.push_back(0);         // start from node 0
        visited_matrix[0] = true;        // mark as visited
        dfs_matrix_helper(0, matrix);    // call helper

        return res_matrix;
    }
};

------------------------------------------------------------
Main Function to Run Both DFS Versions

int main() {
    Solution obj;

    // Create Adjacency List
    vector<vector<int>> adj_list(5);
    adj_list[0] = {1, 2};
    adj_list[1] = {0, 3};
    adj_list[2] = {0, 3, 4};
    adj_list[3] = {1, 2};
    adj_list[4] = {2};

    // Run DFS using adjacency list
    vector<int> result_list = obj.dfs_using_list(adj_list);

    cout << "DFS using Adjacency List: ";
    for (int i = 0; i < result_list.size(); i++) {
        cout << result_list[i] << " ";
    }
    cout << endl;

    // Create Adjacency Matrix (5x5)
    vector<vector<int>> adj_matrix = {
        {0,1,1,0,0},  // Node 0 connected to 1 and 2
        {1,0,0,1,0},  // Node 1 connected to 0 and 3
        {1,0,0,1,1},  // Node 2 connected to 0, 3, and 4
        {0,1,1,0,0},  // Node 3 connected to 1 and 2
        {0,0,1,0,0}   // Node 4 connected to 2
    };

    // Run DFS using adjacency matrix
    vector<int> result_matrix = obj.dfs_using_matrix(adj_matrix);

    cout << "DFS using Adjacency Matrix: ";
    for (int i = 0; i < result_matrix.size(); i++) {
        cout << result_matrix[i] << " ";
    }
    cout << endl;

    return 0;
}

------------------------------------------------------------
Expected Output (based on neighbor order):

DFS using Adjacency List: 0 1 3 2 4  
DFS using Adjacency Matrix: 0 1 3 2 4

Note: The DFS path may vary based on neighbor order in the input.

------------------------------------------------------------
How DFS Works (Simple Steps):

1. Start from node 0
2. Visit a neighbor (e.g., 1), mark it visited
3. From that neighbor, go to another neighbor (e.g., 3)
4. Repeat until no unvisited neighbors, then backtrack
5. Continue with next unvisited node if needed

------------------------------------------------------------
Time and Space Complexity:

- Time Complexity:
  - Adjacency List: O(V + E)
  - Adjacency Matrix: O(V^2)

- Space Complexity:
  - O(V) for visited map
  - O(V) recursion stack space in worst case

------------------------------------------------------------
Summary:

- DFS explores graph deeply before backtracking
- Recursive implementation is clean and easy
- Works for both list and matrix formats
- Best for checking connectivity or path existence
