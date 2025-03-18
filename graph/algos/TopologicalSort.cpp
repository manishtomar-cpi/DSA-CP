#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class TopologicaSort
{
private:
    vector<vector<int>> matrix;
    int edges;
    int vertexes;
    vector<int> inDegree; // used to detect the on how many tasks(other vertex) that vertex is depend
    queue<int> sortTasks;

public:
    TopologicaSort(int vertexSize, int edgeSize) : vertexes(vertexSize), edges(edgeSize), matrix(vertexSize, vector<int>(vertexSize, 0)), inDegree(vertexSize, 0) {};

    void makegraph()
    {
        int firstVertex;
        int secondVertex;
        for (int i = 0; i < edges; i++)
        {
            cout << "enter " << i + 1 << " edge (both vertex): ";
            cin >> firstVertex >> secondVertex;
            if (firstVertex < 0 || firstVertex >= vertexes || secondVertex < 0 || secondVertex >= vertexes)
            {
                cout << "invalid vertex!" << endl;
                i--;
                continue;
            }
            matrix[firstVertex][secondVertex] = 1;
        }
    }
    void printGraph()
    {
        for (int i = 0; i < vertexes; i++)
        {
            for (int j = 0; j < vertexes; j++)
            {
                if (matrix[i][j] == 1)
                {
                    cout << i << " -> " << j << endl;
                }
            }
        }
    }

    /*
    Algorithm
    1. Calculate In-Degree:
    - Compute the in-degree (number of incoming edges) of each vertex.
    2. Initialize Queue:
    - Enqueue all vertices with in-degree `0`.
    3. Process Queue:
    - Dequeue a vertex, append it to the result.
    - Reduce in-degree of its adjacent vertices by `1`.
    - If any adjacent vertex's in-degree becomes `0`, enqueue it.
    4. Repeat Until Queue is Empty.
    */
    vector<int> topologicalSort()
    {
        vector<int> res;
        // STEP1: first fill the indegree vector to find the degree of each vertex;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 1)
                {
                    // cout << i << " -> " << j << endl;
                    inDegree[j]++;
                }
            }
        }
        cout << "++++++++++INDEGREE ARRAY+++++++" << endl;
        for (int i = 0; i < inDegree.size(); i++)
        {
            cout << inDegree[i] << " ";
        }
        cout << endl;

        // STEP2: fill the queue with the vertex have 0 dependencies
        for (int i = 0; i < inDegree.size(); i++)
        {
            if (inDegree[i] == 0)
            {
                sortTasks.push(i);
            }
        }

        // STEP3: iterate till queue became empty
        // 3.1 - in each iteration print the front one and decrease the degree of the vertex which depends on it to 1;
        // 3.1- if any vertex dependiencies became empty push it to queue
        while (!sortTasks.empty())
        {
            int first = sortTasks.front();
            sortTasks.pop();
            cout << first;
            res.push_back(first);

            // check the graph -> which vertex is depends on the current vertex
            for (int i = 0; i < matrix[0].size(); i++)
            {
                // if found anyone
                if (matrix[first][i] == 1)
                {
                    // decrease the degree of that vertex by one becuase one of the dependiecy of that vertex is completed
                    inDegree[i]--;

                    // if the degree of that vertex became 0 then add in queue
                    if (inDegree[i] == 0)
                    {
                        sortTasks.push(i);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    TopologicaSort t1(6, 6);
    t1.makegraph();
    t1.printGraph();
    t1.topologicalSort();

    return 0;
}