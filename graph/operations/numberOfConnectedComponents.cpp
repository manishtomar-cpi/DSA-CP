#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph
{
private:
    int edges;
    int vertexes;
    vector<vector<int>> matrix;
    unordered_map<int, bool> visited; // Stores visited nodes

public:
    Graph(int vertex_size, int edge_size) : edges(edge_size), vertexes(vertex_size), matrix(vertex_size, vector<int>(vertex_size, 0))
    {
        // Initialize visited map with all false
        for (int i = 0; i < vertex_size; i++)
        {
            visited[i] = false;
        }
    }

    void createGraph()
    {
        cout << "Creating graph for " << vertexes << " vertices and " << edges << " edges" << endl;

        int firstVertex, secondVertex;

        for (int i = 0; i < edges; i++)
        {
            cout << "Enter " << i + 1 << " edge (both vertices): ";
            cin >> firstVertex >> secondVertex;

            if (firstVertex < 0 || firstVertex >= vertexes || secondVertex < 0 || secondVertex >= vertexes)
            {
                cout << "Invalid index! Add between (0 and " << vertexes - 1 << ")" << endl;
                i--; // Retry input
                continue;
            }

            matrix[firstVertex][secondVertex] = 1;
            matrix[secondVertex][firstVertex] = 1;
        }

        cout << "Graph generated!" << endl;
    }
    // no of connected components means how many diffrent components we have in the graph

    // this function helps us travers the connected components we are doing BFS here
    // Helper function for BFS traversal
    void noOfConnectedComponentsHelper(int startingIndex)
    {
        queue<int> current;
        current.push(startingIndex);
        visited[startingIndex] = true; // Mark as visited when pushing

        while (!current.empty())
        {
            int curr = current.front();
            current.pop();

            for (int i = 0; i < vertexes; i++)
            {
                if (matrix[curr][i] == 1 && !visited[i])
                {
                    current.push(i);
                    visited[i] = true; // Mark visited when pushing
                }
            }
        }
    }
    // start from 0 yes we have zero is unvisited at first -> after first pass we will travers visited again and watch for unvisited
    int noOfConnectedComponents()
    {
        int connected = 0;

        for (int i = 0; i < vertexes; i++)
        {
            if (!visited[i])
            {
                connected++;
                noOfConnectedComponentsHelper(i);
            }
        }
        return connected;
    }
};

int main()
{
    Graph g1(8, 6);
    g1.createGraph();
    cout << "Number of Connected Components: " << g1.noOfConnectedComponents() << endl;

    return 0;
}
