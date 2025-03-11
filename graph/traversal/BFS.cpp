#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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
    BFS (Breadth-First Search) is a graph traversal algorithm that explores all neighbors of a node before moving to their neighbors. It uses a queue (FIFO) for traversal.
    
    Push the startingVertex into the queue.
    Mark startingVertex as visited.
    Loop until the queue is empty:
    Dequeue the front element (current).
    Print current (Visit the node).
    Check all possible neighbors of current:
    If an edge exists (matrix[current][i] == 1) and the node is not visited:
    Push it into the queue.
    Mark it as visited (to prevent re-visiting).

    Function BFS(startingVertex):
    1. Initialize an empty queue
    2. Initialize visited array to all false
    3. Push startingVertex into queue
    4. Mark startingVertex as visited

    5. While queue is not empty:
        a. Pop front element from queue (current)
        b. Print current
        c. For each vertex i in Matrix:
           - If (edge exists between current and i) AND (i is not visited):
               - Push i into queue
               - Mark i as visited

    */
    void BFS_For_Connected_Graph(int startingVertex)
    {
        // take queue for ordering
        queue<int> adjacent_Vertex;

        // first push first vertex
        adjacent_Vertex.push(startingVertex);

        // iterate till queue became empty
        while (!adjacent_Vertex.empty())
        {
            int current = adjacent_Vertex.front();
            adjacent_Vertex.pop();
            cout << current << endl;

            // make the curren to true ->overcome re visited
            visited[current] = true;
            for (int i = 0; i < vertex; i++)
            {
                if (matrix[current][i] == 1 && visited[i] == false)
                {
                    adjacent_Vertex.push(i);

                    // because it is added in queue should not visit again
                    visited[i] = true;
                }
            }
        }
    }
};

int main()
{
    Graph g1(7, 8);
    g1.makeGraph();
    g1.BFS_For_Connected_Graph(0);

    return 0;
}