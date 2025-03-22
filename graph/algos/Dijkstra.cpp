#include <iostream>
#include <vector>
using namespace std;

class Dijkstra
{
private:
    int edges;
    int vertexes;
    vector<vector<int>> matrix;
    vector<int> distance;  // for mantain the distance
    vector<bool> included; // check if the vertex is included or not

    void printSortestDistance()
    {
        for (int i = 0; i < distance.size(); i++)
        {
            cout << distance[i] << " ";
        }
        cout << endl;
    }

    int smallest(vector<int> &vec)
    {
        int min = INT_MAX;
        int marker = -1;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] < min && !included[i]) // because we need to select the nextMin which is not included
            {
                min = vec[i];
                marker = i;
            }
        }
        return marker;
    }

public:
    Dijkstra(int vertex_size, int edge_size) : vertexes(vertex_size), edges(edge_size), matrix(vertex_size, vector<int>(vertex_size, INT_MAX)), distance(vertex_size, INT_MAX), included(vertex_size, false) {};

    void makeGraph()
    {
        cout << "Making graph for vertex " << vertexes << " and edge " << edges << endl;
        for (int i = 0; i < edges; i++)
        {
            cout << "Enter " << i + 1 << " edge (both vertex): ";
            int firstVertex, secondVertex, weight = 0;
            cin >> firstVertex >> secondVertex;
            cout << endl;
            if (firstVertex < 0 || firstVertex >= vertexes || secondVertex < 0 || secondVertex >= vertexes)
            {
                cout << "please enter valid vertex!" << endl;
                i--;
                continue;
            }
            cout << "Enter weight of this edge: ";
            cin >> weight;
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

            for (int j = 0; j < vertexes; j++)
            {
                if (matrix[i][j] != INT_MAX)
                {
                    cout << i << "  " << j << " - " << matrix[i][j] << endl;
                }
            }
        }
    }
    /*
    Algorithm Steps
    Initialize distances:
        Set the source node’s distance to 0.
        Set all other nodes’ distances to ∞ (infinity).
        Use a priority queue (or a simple array) to track the nearest node.

    Pick the node with the smallest distance (start from source).
        Mark it as visited (included in shortest path set).
        Update distances for neighboring nodes.

    Repeat until all nodes are processed.
        Always pick the next nearest node.
        Update distances if a shorter path is found.

    */

    vector<int> shortestPath(int startVertex)
    {
        // STEP1: update the distanc array according to the starting vertex
        distance[startVertex] = 0; // mark as '0' because from this vertex we will fi d the shortest path for all vertexes;

        // iterate to number of vertexes times because we will find for each vertex
        for (int i = 0; i < matrix[0].size(); i++)
        {
            // STEP2: find the next minimum
            int nextMin = smallest(distance);
            if (nextMin == -1)
                break; // if no vertex left

            // STEP: 3 traverse the neighbor of the vertex if the distance found min update the distance array 
            for (int i = 0; i < matrix[0].size(); i++)
            {
                if (matrix[nextMin][i] != INT_MAX && !included[i] && distance[nextMin] + matrix[nextMin][i] < distance[i]) // so we will check the neighbor of the next min which do not included and the distance to the vertex is less then the currenct distance + distance of the neighbor vertex
                {
                    distance[i] = matrix[nextMin][i] + distance[nextMin];
                }
            }
            included[nextMin] = true;
        }

        printSortestDistance();

        return distance;
    }
};

int main()
{
    Dijkstra d1(5, 6);
    d1.makeGraph();
    d1.printGraph();
    d1.shortestPath(0);

    return 0;
}