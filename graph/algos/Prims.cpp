#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int edges;
    int vertexes;
    vector<vector<int>> matrix;

    // for prism
    vector<vector<int>> spanning_tree; // to make spanning tree of all minimum edges
    vector<int> near;                  // for finding nearest
    int minEdge;                       // use everywhere for finding the minimum

public:
    Graph(int vertex_size, int edge_size) : vertexes(vertex_size), edges(edge_size), matrix(vertex_size, vector<int>(vertex_size, INT_MAX)), near(vertex_size, INT_MAX), spanning_tree(2, vector<int>(vertex_size - 1)) {};

public:
    void makeGraph()
    {
        //! we are making graph from '0' so the 0 is also the vertex thats why the loop starts with zero
        cout << "\nCreating Graph with " << vertexes << " vertices and " << edges << " edges.\n";
        for (int i = 0; i < edges; i++)
        {
            int firstVertex, secondVertex, weight;
            cout << "Enter edge " << i + 1 << " (two vertex indices): ";
            cin >> firstVertex >> secondVertex;
            cout << "Enter weight of this edge: ";
            cin >> weight;

            // if user added invalid indexes
            if (firstVertex < 0 || firstVertex >= vertexes || secondVertex < 0 || secondVertex >= vertexes)
            {
                cout << "Invalid vertices! Please enter values between 0 and " << vertexes - 1 << ".\n";
                i--; // Retry the same edge
                continue;
            }

            // because edges are bydirectional
            matrix[firstVertex][secondVertex] = weight;
            matrix[secondVertex][firstVertex] = weight;
        }

        cout << "graph generated!" << endl;
    }

    void printGraph()
    {
        int i = 0;
        int j = 0;
        for (int i = 0; i < vertexes; i++)
        {

            for (int j = i; j < vertexes; j++)
            {
                // if the value in matrix is not min the it should be edge
                if (matrix[i][j] != INT_MAX)
                {
                    cout << i << " -> " << j << " = " << matrix[i][j] << endl;
                }
            }
        }
    }

    int minCostOfSpanningTree()
    {
        int minimumCost = 0;

        // Iterate through the spanning tree edges
        for (int i = 0; i < vertexes - 1; i++) // Since spanning tree contains vertex-1 edges
        {
            int u = spanning_tree[0][i]; // First vertex of the edge
            int v = spanning_tree[1][i]; // Second vertex of the edge

            // Add the weight of the edge (u, v)
            minimumCost += matrix[u][v];
        }

        return minimumCost;
    }

    /*
        1- Initialize the spanning tree with a single vertex.
        2- Find the edge with the minimum weight connecting a vertex in the MST to a vertex outside.
        3- Add the selected edge and vertex to the MST.
        4- Update the "near" array for all vertices.
        5- Repeat steps 2–4 until all vertices are included in the MST.
    */
    int prims()
    {
        int firstMinVertex = -1;
        int secondMinVertex = -1;
        minEdge = INT_MAX;
        // STEP 1: to find the minimum weight edge
        for (int i = 0; i < vertexes; i++)
        {
            // taking only upper trangular matrix, because the graph is bidirectional
            for (int j = i + 1; j < vertexes; j++)
            {
                // if any of the edge have lower then the current mmin weight, updating the min and also storing the vertexes.
                if (matrix[i][j] < minEdge)
                {
                    minEdge = matrix[i][j];
                    firstMinVertex = i;
                    secondMinVertex = j;
                }
            }
        }

        // STEP 2: update the spanning tree accordingly
        spanning_tree[0][0] = firstMinVertex;
        spanning_tree[1][0] = secondMinVertex;

        // update the near array too because it will helps us to find the nearest min
        near[firstMinVertex] = near[secondMinVertex] = -1; // why -1 because we are taking graph from '0' so we would have the edge 0 anywhere minimum

        // STEP 3: update the near array according to the nearest edge we found to see which edge is now near of the first near edge

        // in this iteration we are checking all the edges respect to the first min edge
        for (int i = 0; i < vertexes; i++)
        {

            // if the distance is lesser then the firstMinVertex then update the near array and filled the firstMinVertex
            if (near[i] != -1)
            {
                if (matrix[i][firstMinVertex] < matrix[i][secondMinVertex])
                {
                    near[i] = firstMinVertex;
                }
                else
                {
                    near[i] = secondMinVertex;
                }
            }
        }

        // STEP: 4 iterate vertex-2 times and find the next min edge by the help of near array and update it. ]
        // why vertex-2 because we already found the first min edge and the total min edge in spanning tree should be vertex-1
        //! we cant take vertex-2 because when we go to the
        //!   spanning_tree[0][i] = k; // becaue the next min edge is matrix[k][near[k]]; -> this will override the current spanning tree, and when we calculate min cost we get the infinity because of incorrect index
        //! that's why we starts loop from i=1 and itrtate till vertex-1
        //! spanning_tree[1][i] = near[k];
        //! near[k] = -1; // because we added k in tree

        for (int i = 1; i < vertexes - 1; i++)
        {
            int minDistance = INT_MAX; // why take this inside first loop because on each itertion it will find the next min edge and then update the near array then when we come next iteration we will stsrt form max
            int k = -1;                // for updating the near array respect to the vertex found new

            // STEP :4.1 - to found the new min edge
            for (int j = 0; j < vertexes; j++)
            {
                if (near[j] != -1 && matrix[j][near[j]] < minDistance)
                {
                    minDistance = matrix[j][near[j]];
                    k = j; // The vertex to be added
                }
            }

            // now update the spanning tree according to the new min edge
            spanning_tree[0][i] = k; // becaue the next min edge is matrix[k][near[k]];
            spanning_tree[1][i] = near[k];
            near[k] = -1; // because we added k in tree

            // STEP 4.2: -  update the near array according to the new edge
            for (int j = 0; j < vertexes; j++)
            {
                if (near[j] != 1 && matrix[j][k] < matrix[j][near[j]])
                {
                    near[j] = k; // because the edge have less weight now respected to k;
                }
            }
        }

        return minCostOfSpanningTree();
    }
};

int main()
{

    Graph g1(7, 9);
    g1.makeGraph();
    g1.printGraph();
    cout << g1.prims() << endl;

    return 0;
}