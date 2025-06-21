#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Graph
{
private:
    int vertex;
    int edge;
    vector<vector<int>> matrix;
    unordered_map<int, bool> visited;

public:
    Graph(int ver_size, int edge_size) : vertex(ver_size), edge(edge_size), matrix(ver_size + 1, vector<int>(ver_size + 1, 0))
    {
        for (int i = 1; i <= vertex; i++)
        {
            visited[i] = false;
        }
    };

    void make_graph()
    {
        cout << "making graph with " << vertex << " vertex and " << edge << " edges..." << endl;
        for (int i = 0; i < edge; i++)
        {
            int firstVer;
            int secondVer;
            cout << "enter " << i + 1 << " edge (both vertexes): ";
            cin >> firstVer >> secondVer;
            if (firstVer > vertex || firstVer < 1 && secondVer < 1 || secondVer > vertex)
            {
                cout << "Invalid vertexes try again!" << endl;
                i--;
                continue;
            }
            matrix[firstVer][secondVer] = 1;
            cout << "make connection to " << secondVer << " -> " << firstVer << " if yes press 1: ";
            int preference;
            cin >> preference;
            if (preference == 1)
            {
                matrix[secondVer][firstVer] = 1;
            }
        }
        cout << "graph generated!" << endl;
    }

    void printGraph()
    {
        for (int i = 1; i <= vertex; i++)
        {
            cout << i << ": ";
            for (int j = 1; j <= vertex; j++)
            {
                if (matrix[i][j] == 1)
                {
                    cout << j << ", ";
                }
            }
            cout << endl;
        }
    }

    void print_bfs(int startingIndex)
    {
        queue<int> vertexes;

        vertexes.push(startingIndex);
        visited[startingIndex] = true;
        while (!vertexes.empty())
        {
            int current = vertexes.front();
            vertexes.pop();
            cout << current << " ";
            for (int i = 1; i <= vertex; i++)
            {
                if (matrix[current][i] == 1 && !visited[i])
                {
                    vertexes.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void BFS()
    {
        int connected = 0;
        cout << "++++++++BFS++++++++++" << endl;

        for (int i = 1; i <= vertex; i++)
        {
            if (!visited[i])
            {
                connected++;
                print_bfs(i);
            }
        }
        cout << connected << endl; // give number of components in the graph
    }

    void print_dfs(int startingVertex)
    {
        stack<int> vertexes;
        vertexes.push(startingVertex);
        visited[startingVertex] = true;
        while (!vertexes.empty())
        {
            int current = vertexes.top();
            cout << current << " ";
            vertexes.pop();
            for (int i = vertex; i >= 1; i--)
            {
                if (matrix[current][i] == 1 && !visited[i])
                {
                    vertexes.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void DFS()
    {
        cout << "++++++++DFS++++++++++" << endl;
        for (int i = 1; i <= vertex; i++)
        {
            if (!visited[i])
            {
                print_dfs(i);
            }
        }
    }
};

int main()
{
    Graph g1(8, 6);
    g1.make_graph();
    g1.printGraph();
    // g1.BFS();
    g1.DFS();

    return 0;
}