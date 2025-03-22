#include <iostream>
#include <vector>
using namespace std;

class Kruskal
{
private:
    int edges;
    int vertexes;
    vector<vector<int>> kruskal_graph;
    vector<vector<int>> spanning_tree;
    vector<int> include;
    vector<int> sets;

public:
    Kruskal(int vertex_size, int edge_size) : edges(edge_size), vertexes(vertex_size), kruskal_graph(3, vector<int>(edge_size)), spanning_tree(3, vector<int>(vertex_size - 1)), include(edge_size, 0), sets(vertex_size, -1) {};

    void makeGraph()
    {
        cout << "Making graph" << endl;

        for (int i = 0; i < edges; i++)
        {
            int firstVertex = 0;
            int secondVertex = 0;
            int weight = 0;
            cout << "enter " << i + 1 << " edge (both vertexes): ";
            cin >> firstVertex >> secondVertex;
            cout << "enter weight of this vertex: ";
            cin >> weight;

            // filling graph accordingly
            kruskal_graph[0][i] = firstVertex;
            kruskal_graph[1][i] = secondVertex;
            kruskal_graph[2][i] = weight;
        }
    }

    void print_graph()
    {
        cout << "Graph Edges:\n";
        for (int i = 0; i < edges; i++)
        {
            cout << kruskal_graph[0][i] << " - " << kruskal_graph[1][i] << " : " << kruskal_graph[2][i] << endl;
        }
    }

    int find_parent(int vertex)
    {
        // so this function used to find the cycle id the parent of both the vertex is same then they should make cycle
        int i = vertex;

        // we will travers the sets array till we get the negative value (negative value means parent of inself in the sets array)
        while (sets[i] >= 0)
        {
            i = sets[i];
        }
        return i;
    }

    void vertex_union(int first_v, int second_v)
    {
        // Union by Size: The root with a larger size (more negative) should remain the root
        int root1 = find_parent(first_v);
        int root2 = find_parent(second_v);

        if (sets[root1] < sets[root2]) // If root1 has more elements (more negative)
        {
            sets[root1] += sets[root2]; // Merge root2 into root1
            sets[root2] = root1;
        }
        else
        {
            sets[root2] += sets[root1]; // Merge root1 into root2
            sets[root1] = root2;
        }
    }
    /*
        Steps of Kruskal's Algorithm
        1: Sort all edges by increasing weight.
        2: Pick the smallest edge that doesn't form a cycle.
        3: Add the edge to the spanning tree.
        4: Repeat until we have (V - 1) edges (where V is the number of vertices).
    */

    void spanning_tree_func()
    {
        int edges_in_mst = 0; // Track selected edges count

        for (int i = 0; i < vertexes - 1; i++) // because spanning tree should have vertex-1 edges
        {
            int min = INT16_MAX;
            int markerOfMin = -1;
            // first find minimum edge which is not included yet
            for (int j = 0; j < edges; j++)
            {
                if (kruskal_graph[2][j] < min && include[j] != 1)
                {
                    min = kruskal_graph[2][j];
                    markerOfMin = j;
                }
            }
            if (markerOfMin == -1)
            {
                break; // if no edge found
            }

            // checking the cycle
            if (find_parent(kruskal_graph[0][markerOfMin]) != find_parent(kruskal_graph[1][markerOfMin]))
            {
                // if all good add that edge in the spanning tree;
                spanning_tree[0][edges_in_mst] = kruskal_graph[0][markerOfMin];
                spanning_tree[1][edges_in_mst] = kruskal_graph[1][markerOfMin];
                spanning_tree[2][edges_in_mst] = kruskal_graph[2][markerOfMin];
                vertex_union(kruskal_graph[0][markerOfMin], kruskal_graph[1][markerOfMin]); // union operation -> update union array
                edges_in_mst++;

                cout << "Selected Edge: " << kruskal_graph[0][markerOfMin] << " - " << kruskal_graph[1][markerOfMin] << " : " << min << endl; //! debugging
            }
            else
            {
                // when cycle detected
                i--;
            }
            include[markerOfMin] = 1; // at last include that edge
        }
    }

    void printSpanningTree()
    {
        for (int i = 0; i < spanning_tree[0].size(); i++)
        {
            cout << spanning_tree[0][i] << " " << spanning_tree[1][i] << " -> " << spanning_tree[2][i] << endl;
        }
    }

    int minCost()
    {
        int sum = 0;
        for (int i = 0; i < spanning_tree[0].size(); i++)
        {
            // because on the third row we have all the weights
            sum += spanning_tree[2][i];
        }
        return sum;
    }
};

int main()
{
    Kruskal k1(7, 9);
    k1.makeGraph();
    k1.print_graph();
    k1.spanning_tree_func();
    k1.printSpanningTree();
    cout << k1.minCost() << endl;

    return 0;
}