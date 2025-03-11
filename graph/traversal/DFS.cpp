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

            // because edges are bydirectional
            matrix[firstVertex][secondVertex] = 1;
            matrix[secondVertex][firstVertex] = 1;
        }

        cout << "graph generated!" << endl;
    }
    /*
    DFS (Depth-First Search) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It uses recursion or a stack to traverse a graph.

    Step 1: Print the current vertex.
    Step 2: Mark the vertex as visited.
    Step 3: Traverse all adjacent vertices.
    Step 4: If an adjacent vertex is not visited, call DFS(next_vertex) recursively.

    Function DFS(Graph, startingVertex, visited):
        1. Print the startingVertex
        2. Mark startingVertex as visited
        3. For each vertex i in Graph:
             a. If there is an edge (startingVertex → i) AND i is not visited:
                  - Call DFS(Graph, i, visited)

    */
    void DFS_Print(int startingVertex)
    {
        cout << startingVertex << endl;
        // first make the starting as true because edges are bydirectional so we will not come again on the visited one
        visited[startingVertex] = true;

        // now traverse all the vertexes  in the row and check the connection respected to the starting vertex
        for (int i = 0; i < matrix.size(); i++)
        {

            // if seen connectiion thne call recusrion on the vertex then we will print all the connection of that vertex
            if (matrix[startingVertex][i] == 1 && visited[i] == false)
            {
                DFS_Print(i);
            }
        }
    }


    //made for Disconnected graphs we are traversing the visited map and check which vertex is currently not visited 
    void DFS()
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            //if not visited
            if (!visited[i])
            {
                //visit that vertex
                DFS_Print(i);
            }
        }
    }
};

int main()
{
    Graph g1(8, 6);
    g1.makeGraph();
    g1.DFS();

    return 0;
}