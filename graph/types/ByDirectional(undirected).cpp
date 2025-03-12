#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph
{
private:
    int vertex;
    int edges;
    vector<vector<int>> matrix;
    /*
    vector<vector<int>> matrix(No_of_rows, vector<int>(no_o_cols, initial_value)); syntax of delearing the matrix
    We define a vector<vector<int>> (2D vector) with 'rows' number of rows and 'cols' number of columns.
    The inner vector (vector<int>(cols, 0)) initializes each row with 'cols' number of elements, all set to 0.
    We print the matrix using nested loops
    */

    unordered_map<int, bool> visited; // created the map for recursive print

public:
    Graph(int vertex_size, int edge_Size) : vertex(vertex_size), edges(edge_Size), matrix(vertex_size, vector<int>(vertex_size, 0)) {}; // now we declared the size of matrix and number of colomns of the matrix

    // function for felling the matrix, stsrt form 1st edge and till we fill all the edges
    void makeGraph()
    {
        //! we are making graph from '0' so the 0 is also the vertex thats why the loop starts with zero
        cout << "\nCreating Graph with " << vertex << " vertices and " << edges << " edges.\n";
        for (int i = 0; i < edges; i++)
        {
            int firstVertex, secondVertex;
            cout << "Enter edge " << i + 1 << " (two vertex indices): ";
            cin >> firstVertex >> secondVertex;

            // if user added invalid indexes
            if (firstVertex < 0 || firstVertex >= vertex || secondVertex < 0 || secondVertex >= vertex)
            {
                cout << "Invalid vertices! Please enter values between 0 and " << vertex - 1 << ".\n";
                i--; // Retry the same edge
                continue;
            }

            // because edges are bydirectional -> which means if we have path from 'A' to 'B' their should be path from 'B' to 'A'.
            matrix[firstVertex][secondVertex] = 1;
            matrix[secondVertex][firstVertex] = 1;
        }

        cout << "graph generated!" << endl;
    }

    void printGraph()
    {
        for (int i = 0; i < vertex; i++)
        {
            cout << i << ": ";
            for (int j = i; j < vertex; j++)
            {
                if (matrix[i][j] == 1)
                {
                    cout << j << ",";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g1(7, 8);
    g1.makeGraph();
    g1.printGraph();

    return 0;
}