#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    unordered_map<int, bool> visited;
    unordered_map<int, bool> cycle;
    stack<int> st;

    void setup_cycle(int size)
    {
        for (int i = 0; i < size; i++)
        {
            cycle[i] = false;
        }
    }

    bool helper(int size, int startPoint, vector<vector<int>> &edges)
    {
        setup_cycle(size);
        st.push(startPoint);
        while (!st.empty())
        {
            setup_cycle(size);

            int current = st.top();
            st.pop();
            visited[current] = true;
            for (int i = 0; i < edges[current].size(); i++)
            {
                if (cycle[edges[current][i]])
                {
                    return true;
                }
                else
                {
                    if (!visited[edges[current][i]])
                    {
                        st.push(edges[current][i]);
                        visited[edges[current][i]] = true;
                        cycle[edges[current][i]] = true;
                    }
                }
            }
        }
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool cycle = helper(V, i, adj);
                if (cycle)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    int v = 4;
    vector<vector<int>> vec = {{0, 3}, {0, 1}, {1, 3}};
    Solution s1;
    cout << boolalpha;
    cout << s1.isCyclic(v, vec) << endl;
    return 0;
}