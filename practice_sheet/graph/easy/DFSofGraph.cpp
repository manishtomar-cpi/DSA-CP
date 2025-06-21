#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
  public:
  vector<int>res;
  unordered_map<int,bool> visited;
  void dfs_helper(int startingIndex, vector<vector<int>> &adj){
      for(int i =0;i<adj[startingIndex].size();i++){
         int neighbor = adj[startingIndex][i];
         if(!visited[neighbor]){
             res.push_back(neighbor);
             visited[neighbor]=true;
             dfs_helper(neighbor,adj);
         }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
       res.push_back(0);
       visited[0]=true;
       dfs_helper(0,adj);
       
       return res;
    }
};
int main()
{
    vector<vector<int>> adj = {
        {1, 2, 4, 8}, // Node 0
        {0, 5, 6, 9}, // Node 1
        {0, 4},       // Node 2
        {7, 8},       // Node 3
        {0, 2},       // Node 4
        {1, 8},       // Node 5
        {1, 7, 9},    // Node 6
        {3, 6},       // Node 7
        {0, 3, 5},    // Node 8
        {1, 6}        // Node 9
    };

    Solution s1;
    s1.dfs(adj);

    return 0;
}