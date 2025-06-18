#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int vertex;
    int edge;
    vector<vector<int>> matrix;

public:
    Graph(int ver_size, int edge_size) : vertex(ver_size), edge(edge_size), matrix(ver_size, vector<int>(ver_size, 0)) {};

    void makeGraph()
    {
        cout << "creating graph with " << vertex << " vertex and " << edge << " ..." << endl;

        for (int i = 0; i < edge; i++)
        {
            int firstVertex;
            int secondVertex;
            cout << "Enter " << i + 1 << " edge (both vertex): ";
            cin >> firstVertex >> secondVertex;
            if (firstVertex < 0 || firstVertex >= vertex || secondVertex < 0 || secondVertex >= vertex)
            {
                cout << "Invalid vertices! Please enter values between 0 and " << vertex - 1 << ".\n";
                i--; // Retry the same edge
                continue;
            }
            if (matrix[firstVertex][secondVertex] == 1)
            {
                cout << "already a edge b/w these vertexes!" << endl;
                i--;
                continue;
            }
            matrix[firstVertex][secondVertex] = 1;
        }
        cout << "graph generated!" << endl;
    }

    void printGraph()
    {
        for (int i = 0; i < vertex; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < vertex; j++)
            {
                if (matrix[i][j] == 1)
                {
                    cout << j << " , ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g1(6, 5);
    g1.makeGraph();
    g1.printGraph();
}