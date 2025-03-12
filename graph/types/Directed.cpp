#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph
{
private:
    int vertex_size;
    int edge_size;
    vector<vector<int>> matrix;
    unordered_map<int, bool> visited; // for traversing whole graph

public:
    Graph(int vs, int es) : vertex_size(vs), edge_size(es), matrix(vs, vector<int>(vs, 0))
    {
        for (int i = 0; i < vertex_size; i++)
        {
            visited[i] = false;
        }
    };

    void makeGraph()
    {
        cout << "Making graph for vertex " << vertex_size << " and edge " << edge_size << endl;
        for (int i = 0; i < edge_size; i++)
        {
            cout << "Enter " << i + 1 << " edge (both vertex): ";
            int firstVertex, secondVertex = 0;
            cin >> firstVertex >> secondVertex;
            cout << endl;
            if (firstVertex < 0 || firstVertex >= vertex_size || secondVertex < 0 || secondVertex >= vertex_size)
            {
                cout << "please enter valid vertex!" << endl;
                i--;
                continue;
            }
            // now we have directed graph only one direction A -> B //!not B -> A
            matrix[firstVertex][secondVertex] = 1;
        }
        cout << "graph generated!" << endl;
    }

    void Print_DFS(int startingIndex)
    {
        cout << startingIndex << endl;

        visited[startingIndex] = true;
        for (int i = 0; i < vertex_size; i++)
        {
            if (matrix[startingIndex][i] == 1 && visited[i] == false)
            {
                Print_DFS(i);
            }
        }
    }

    void DFS()
    {
        for (int i = 0; i < vertex_size; i++)
        {
            if (visited[i] == false)
            {
                Print_DFS(i);
            }
        }
    }
    void printGraph()
    {
        int i = 0;
        int j = 0;
        for (int i = 0; i < vertex_size; i++)
        {

            for (int j = 0; j < vertex_size; j++)
            {
                if (matrix[i][j] == 1)
                {
                    cout << i << " -> " << j << endl;
                }
            }
        }
    }
};

int main()
{
    Graph g1(4, 4);
    g1.makeGraph();
    g1.DFS();
    g1.printGraph();

    return 0;
}