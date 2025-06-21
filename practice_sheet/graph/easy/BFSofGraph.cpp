#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

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